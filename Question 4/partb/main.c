#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pid; 
	pid = fork();

	if(pid == 0)
	{
		execl("./interp","interp","CHILD_ARG1","CHILD_ARG2",NULL);
	}
	else{
		wait(NULL);
		printf("Parent process complete");
	}
	return 0;
}
