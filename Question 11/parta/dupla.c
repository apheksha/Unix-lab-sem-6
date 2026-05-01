#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1 , fd2;

	fd1 = open("test.txt",O_CREAT | O_RDWR, 0644);

	if(fd1 < 0)
	{
		printf("Error file opeining");
		return 1;
	}

	fd2 = dup(fd1);
	printf("%d %d\n",fd1,fd2);

	return 0;
}
