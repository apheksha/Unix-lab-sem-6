#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

extern char **environ;

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        char *env[] = {"USER=Student", "CITY=India", NULL};
        execle("./echoall", "echoall", "child", NULL, env);
        perror("execle");
        exit(1);
    }
    else
    {
        wait(NULL);

        execve("./echoall", (char*[]){"echoall","parent",NULL}, environ);
        perror("execve");
    }

    return 0;
}
