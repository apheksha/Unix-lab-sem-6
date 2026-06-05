// Write a C program:
// i. To create a child process.
// ii. The child should execute an interpreter file by passing a few arguments.
// iii. Create an interpreter file that has the path of echoall.c file and pass one argument.
// iv. Create echoall.c file which prints the arguments received from both child process and interpreter file.

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
        execl("./interp","interp","CHILD_ARG1","CHILD_ARG2",NULL);
        perror("execl");
        exit(1);
    }

    wait(NULL);

    printf("Parent Completed\n");

    return 0;
}
