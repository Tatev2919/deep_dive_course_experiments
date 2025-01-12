#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("-----------------------------init-------------------------------------\n");
    printf("Process started: PID = %d, Parent PID = %d\n", getpid(), getppid());

    fork(); // First fork
    printf("-------------------------------1-----------------------------------\n");
    printf("After first fork: PID = %d, Parent PID = %d\n", getpid(), getppid());

    fork(); // Second fork
    printf("-------------------------------2-----------------------------------\n");
    printf("After second fork: PID = %d, Parent PID = %d\n", getpid(), getppid());

    fork(); // Third fork
    printf("-------------------------------3-----------------------------------\n");
    printf("After third fork: PID = %d, Parent PID = %d\n", getpid(), getppid());

    sleep(1);
    return 0;
}
