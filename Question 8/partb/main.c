// Write a C program to perform the following operations:
// i. To create a child process.
// ii. The child process should execute a program (using exec()) to show the use of the access function.
// iii. The parent process should wait for the child process to exit.
// iv. Also print the necessary process IDs.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    pid_t pid;

    if(argc!=2)
    {
        printf("Usage: %s <filename>\n",argv[0]);
        return 1;
    }

    pid=fork();

    if(pid<0)
    {
        perror("fork");
        return 1;
    }

    if(pid==0)
    {
        printf("Child PID  : %d\n",getpid());
        printf("Parent PID : %d\n",getppid());

        execl("./p1","p1",argv[1],NULL);

        perror("execl");
        exit(1);
    }

    printf("Parent PID : %d\n",getpid());

    wait(NULL);

    printf("Child Process Completed\n");

    return 0;
}
