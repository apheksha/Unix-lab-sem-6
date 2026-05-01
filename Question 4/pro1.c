#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		if(link(argv[1],argv[2]) == 0)
			printf("Hard link created\n");
		else
			printf("Hard link error");
	}
	else if(argc == 4)
	{
		if(symlink(argv[2], argv[3]) == 0)
			printf("Soft link created");
		else 
			printf("soft link error");
	}
	else
	{
		printf("Invalid argument");
	}
	return 0;
}
