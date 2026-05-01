#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();

    if(pid == 0)
    {
        // Child
        printf("Child process (PID: %d) executing...\n", getpid());

        execl("./a.out", "a.out", "example.txt", NULL);

        printf("Exec failed\n");
    }
    else
    {
        // Parent
        printf("Parent process (PID: %d) executing...\n", getpid());

        wait(NULL);

        printf("Parent process: Child process (PID: %d) has exited.\n", pid);
    }

    return 0;
}
