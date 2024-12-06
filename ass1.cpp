#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process (PID: %d) is running 'ls'\n", getpid());
        execl("/bin/ls", "ls", (char *)NULL);

        perror("execl failed");
        exit(1);
    } else {
        printf("Parent process (PID: %d) created child (PID: %d)\n", getpid(), pid);
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}

