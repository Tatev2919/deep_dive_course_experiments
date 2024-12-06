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
        execl("/bin/grep", "grep", "clock","test.txt", (char *)NULL);
        perror("execl failed");
        exit(1);
    } else {
        //wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}

