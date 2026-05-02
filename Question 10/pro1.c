#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    pid_t pid;

    pid = fork();
    if(pid < 0) exit(1);

    if(pid > 0)
    {
        printf("Daemon PID: %d\n", pid);   // print from parent
        exit(0);
    }

    setsid();

    pid = fork();
    if(pid < 0) exit(1);
    if(pid > 0) exit(0);

    umask(0);
    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    open("/dev/null", O_RDONLY);
    open("/dev/null", O_WRONLY);
    open("/dev/null", O_RDWR);

    while(1)
        sleep(5);

    return 0;
}
