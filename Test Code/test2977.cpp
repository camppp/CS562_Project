#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int execute_command(char* command) {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, (char*)0);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}
