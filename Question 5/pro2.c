#include<stdio.h>
#include<signal.h>

void handler(int n)
{
    printf("\nSIGINT caught\n");
    signal(SIGINT, SIG_DFL);
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while(1);
}
