#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid;

	pid = fork();
	if(pid  == 0)
	{
		execl("./echoall", "echoall", "myarg1","MYARG1",NULL);
	}
	else{
		sleep(1);
		 execl("./echoall","echoall","only 1 arg", NULL);
	}
	return 0;
}
