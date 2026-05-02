#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t p1, p2;
    int status;

    p1 = fork();

    if(p1 == 0)
    {
        printf("Child 1 PID: %d\n", getpid());
        sleep(2);
        exit(1);
    }

    p2 = fork();

    if(p2 == 0)
    {
        printf("Child 2 PID: %d\n", getpid());
        sleep(1);
        exit(2);
    }

    printf("Parent PID: %d\n", getpid());

    waitpid(p1, &status, 0);
    printf("waitpid: Child 1 finished\n");

    wait(&status);
    printf("wait: Remaining child finished\n");

    return 0;
}
