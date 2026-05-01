#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char file[20], buf[20];
	int fd,n;

	printf("Enter the filename:");
	scanf("%s", file);

	printf("Enter n:");
	scanf("%d",&n);

	fd = open(file, O_RDWR);
	read(fd,buf,n);
	buf[n] = '\0';

	lseek(fd,0,SEEK_END);
	dup2(fd,1);
	write(1,buf,strlen(buf));

	close(fd);
}
