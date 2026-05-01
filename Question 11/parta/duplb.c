#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2;

	fd1 = open("test.txt",O_CREAT | O_WRONLY, 0644);

	fd2 = dup2(fd1,0);
	printf("%d %d\n",fd1,fd2);

	write(fd1,"abcdef\n",7);
	printf("abcdef\n");
	 return 0;
}

