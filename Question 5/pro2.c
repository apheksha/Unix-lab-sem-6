#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signo)
{
    printf("\nSIGINT caught. Next Ctrl+C will terminate.\n");

    struct sigaction sa;
    sa.sa_handler = SIG_DFL;          
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if(sigaction(SIGINT, &sa, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }

    printf("Press Ctrl+C to trigger SIGINT\n");

    while(1)
        pause();   

    return 0;
}
