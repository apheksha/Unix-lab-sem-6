#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        execl("./interp", "interp", "CHILD_ARG1", "CHILD_ARG2", NULL);
        perror("execl");
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Parent process complete\n");
    }

    return 0;
}
