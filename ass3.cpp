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
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        perror("execl failed");
        exit(1);
    } else {
        //wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}

