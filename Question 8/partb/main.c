#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    if(pid == 0)
    {
        printf("Child PID: %d Parent PID: %d\n", getpid(), getppid());

        execl("./p1", "p1", "example.txt", (char *)NULL);

        perror("execl");
        exit(1);
    }
    else
    {
        printf("Parent PID: %d waiting for child %d\n", getpid(), pid);

        wait(NULL);

        printf("Child process completed\n");
    }

    return 0;
}
