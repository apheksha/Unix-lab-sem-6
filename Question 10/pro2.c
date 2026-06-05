// Demonstrate the working of wait() and waitpid() system calls.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;
    int status;

    pid1 = fork();

    if(pid1 == 0)
    {
        printf("Child 1 PID : %d\n", getpid());
        sleep(2);
        exit(1);
    }

    pid2 = fork();

    if(pid2 == 0)
    {
        printf("Child 2 PID : %d\n", getpid());
        sleep(1);
        exit(2);
    }

    printf("Parent PID : %d\n", getpid());

    waitpid(pid1, &status, 0);

    if(WIFEXITED(status))
    {
        printf("waitpid collected Child 1, Exit Status = %d\n",
               WEXITSTATUS(status));
    }

    wait(&status);

    if(WIFEXITED(status))
    {
        printf("wait collected remaining Child, Exit Status = %d\n",
               WEXITSTATUS(status));
    }

    return 0;
}
