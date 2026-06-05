// Write a program to perform the following operations:
// i. To create a child process
// ii. The child process should execute a separate program (using exec function) that calculates the addition of two numbers by passing two integer values.
// iii. The parent process should wait for a child to complete

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    pid_t pid;
    int status;

    if(argc!=3)
    {
        printf("Usage: %s <num1> <num2>\n",argv[0]);
        return 1;
    }

    pid=fork();

    if(pid==0)
    {
        execl("./child","child",argv[1],argv[2],NULL);
        perror("execl");
        exit(1);
    }

    wait(&status);

    printf("Child Completed\n");

    return 0;
}
