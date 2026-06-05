// Write a C program to simulate system function.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int my_system(const char *cmd)
{
    pid_t pid;
    int status;

    pid=fork();

    if(pid<0)
    {
        perror("fork");
        return -1;
    }

    if(pid==0)
    {
        execl("/bin/sh","sh","-c",cmd,(char *)NULL);
        perror("execl");
        exit(1);
    }

    waitpid(pid,&status,0);

    return status;
}

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: %s \"command\"\n",argv[0]);
        return 1;
    }

    my_system(argv[1]);

    return 0;
}
