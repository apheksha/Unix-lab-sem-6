#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

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

    umask(0);
    chdir("/");

    close(0);
    close(1);
    close(2);

    open("/dev/null", O_RDONLY);
    open("/dev/null", O_WRONLY);
    open("/dev/null", O_RDWR);

    while(1)
        sleep(5);

    return 0;
}
