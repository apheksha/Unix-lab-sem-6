// Write a program to demonstrate the zombie state of a process and provide the solution for the same.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;

    pid=fork();

    if(pid<0)
    {
        perror("fork");
        return 1;
    }

    if(pid==0)
    {
        printf("Child Exiting. PID : %d\n",getpid());
        exit(0);
    }

    printf("Child PID %d is Zombie for 10 Seconds\n",pid);
    printf("Run : ps -l | grep Z\n");

    sleep(10);

    wait(NULL);

    printf("Zombie Removed Using wait()\n");

    return 0;
}
