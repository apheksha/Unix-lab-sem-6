#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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

    umask(0);
    chdir("/");
    close(0); close(1); close(2); 
    while(1)
        sleep(5);

    return 0;
}
