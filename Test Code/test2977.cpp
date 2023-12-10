#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_command(const char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execl("/bin/sh", "sh", "-c", command, (char *)0);
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }
    return -1;  // Error in execution
}

int main() {
    printf("%d\n", execute_command("ls -l"));
    printf("%d\n", execute_command("cat non_existent_file"));
    return 0;
}
