// Write a C program such that it initializes itself as a Daemon Process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)
    {
        exit(0);
    }

    if (setsid() < 0)
    {
        perror("setsid");
        exit(1);
    }

    umask(0);

    chdir("/");

    printf("Daemon Running PID=%d\n", getpid());

    sleep(2);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1)
    {
        sleep(5);
    }

    return 0;
}
