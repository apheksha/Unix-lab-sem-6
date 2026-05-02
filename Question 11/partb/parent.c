#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    int pid, status;

    if(argc != 3)
    {
        printf("Usage: %s num1 num2\n", argv[0]);
        return 1;
    }

    pid = fork();

    if(pid == 0)
    {
        execl("./child", "child", argv[1], argv[2], NULL);
        perror("execl");
        exit(1);
    }
    else
    {
        wait(&status);
        printf("Child exited with status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
