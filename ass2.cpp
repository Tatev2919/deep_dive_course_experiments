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
        printf("First child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
	execl("/bin/ls", "ls", (char *)NULL);
        exit(0);
    } else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed for second child");
            exit(1);
        } else if (pid2 == 0) {
            printf("Second child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
	    execl("/bin/date", "date", (char *)NULL);
            exit(0);
        } else {
            printf("Parent process (PID: %d) created two children: %d and %d\n", getpid(), pid1, pid2);

            wait(NULL);
            wait(NULL);

            printf("Parent process done\n");
        }
    }

    return 0;
}

