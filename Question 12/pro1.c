#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int pid1, pid2;

    
    pid1 = fork();

    if(pid1 == 0)
    {
        printf("Child 1 pid: %d\n", getpid());
        exit(0);   
    }
    else
    {
        sleep(2);  

        printf("terminated child's pid: %d\n", pid1);

        
        pid2 = fork();

        if(pid2 == 0)
        {
            printf("Child 2 pid is: %d\n", getpid());
            printf("second child, parent pid = %d\n", getppid());
            exit(0);
        }
        else
        {
            wait(NULL);   
            wait(NULL);   
        }
    }

    return 0;
}
