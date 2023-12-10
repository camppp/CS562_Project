#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

const unsigned int NodeNum = 4; // number of child processes

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <node_num>" << endl;
        return 1;
    }

    // open input file
    ifstream input_file(argv[1]);
    if (!input_file) {
        cerr << "Error: unable to open input file " << argv[1] << endl;
        return 1;
    }

    // create child processes
    vector<pid_t> child_pids;
    for (unsigned int i = 0; i < NodeNum; i++) {
        pid_t child_pid = fork();
        if (child_pid == 0) {
            // child process
            break;
        } else if (child_pid > 0) {
            // parent process
            child_pids.push_back(child_pid);
        } else {
            cerr << "Error: fork failed" << endl;
            return 1;
        }
    }

    // set up communication pipes
    vector<int> pipes;
    for (unsigned int i = 0; i < NodeNum; i++) {
        int pipe_fd[2];
        if (pipe(pipe_fd) == -1) {
            cerr << "Error: pipe creation failed" << endl;
            return 1;
        }
        pipes.push_back(pipe_fd[0]);
        pipes.push_back(pipe_fd[1]);
    }

    // read data from input file and send to child processes
    string line;
    while (getline(input_file, line)) {
        for (unsigned int i = 0; i < NodeNum; i++) {
            write(pipes[i * 2 + 1], line.c_str(), line.size());
        }
    }

    // wait for child processes to finish
    for (unsigned int i = 0; i < NodeNum; i++) {
        int status;
        waitpid(child_pids[i], &status, 0);
    }

    // close pipes
    for (unsigned int i = 0; i < NodeNum; i++) {
        close(pipes[i * 2]);
        close(pipes[i * 2 + 1]);
    }

    return 0;
}
