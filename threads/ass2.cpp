#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed for first child");
        exit(1);
    } else if (pid1 == 0) {
	execl("/bin/ls", "ls", (char *)NULL);
        exit(0);
    } else {
        wait(NULL);
        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed for second child");
            exit(1);
        } else if (pid2 == 0) {
	    execl("/bin/date", "date", (char *)NULL);
            exit(0);
        } else {
            wait(NULL);
            printf("Parent process done\n");
        }
    }

    return 0;
}

