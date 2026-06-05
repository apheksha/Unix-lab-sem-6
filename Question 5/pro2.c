// Write a C program using sigaction system call which calls a signal handler on SIGINT signal and then reset the default action of the SIGINT signal.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int signo)
{
    struct sigaction sa;

    printf("\nSIGINT Caught\n");
    printf("Next Ctrl+C Will Terminate Program\n");

    sa.sa_handler=SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;

    sigaction(SIGINT,&sa,NULL);
}

int main()
{
    struct sigaction sa;

    sa.sa_handler=handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;

    sigaction(SIGINT,&sa,NULL);

    printf("Press Ctrl+C\n");

    while(1)
    {
        pause();
    }

    return 0;
}
