#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed");
		exit(1);
	}
	if(pid > 0)
	{
		exit(0);
	}

	setsid();
	printf("Daemon process started with pid : %d\n", getpid());

	while(1)
	{
		sleep(5);
	}
	return 0;
}
