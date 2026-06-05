// Write a C program to perform the following operations:
// i. To create a child and parent process with the use of an echoall file.
// ii. The Child should execute a process that prints the user defined values of environment variables.
// iii. The Parent should execute a process that prints default values for the environment variables.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

extern char **environ;

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
        char *env[]={"USER=Student","CITY=India",NULL};

        execle("./echoall","echoall","child",NULL,env);

        perror("execle");
        exit(1);
    }

    wait(NULL);

    execve("./echoall",(char *[]){"echoall","parent",NULL},environ);

    perror("execve");

    return 0;
}
