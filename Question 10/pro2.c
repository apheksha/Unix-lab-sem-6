#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	int pd1,pd2;

	pd1 = fork();
	if(pd1 == 0)
	{
		printf("First pid :%d\n",getpid());
		sleep(1);
		printf("First wait\n");
		return 0;
	}
	else{
		pd2 = fork();
		if(pd2 == 0)
		{
			printf("Second pid :%d\n", getpid());
			sleep(2);
			printf("Second wait\n");
			return 0;
		}
		else{
			printf("first pid :%d\n", getpid());

			wait(NULL);
			waitpid(pd2, NULL, 0);
		}
	}
	 return 0;
}
