#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;
	char buf[21];
	int n;

	if(argc != 2)
	{
		printf("usage source destination\n",argv[0]);
		return 1;
	}

	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		printf("error opening file");
		return 1;
	}

	n = read(fd, buf, 20);
	buf[n] = '\0';
	printf("first 20: %s\n", buf);

	lseek(fd, 10, SEEK_SET);
	n = read(fd, buf, 20);
	buf[n] = '\0';
	printf("Next 20 from 10: %s\n", buf);
	
	lseek(fd, 10, SEEK_CUR);
	n = read(fd, buf, 20);
	buf[n] = '\0'; 
	printf("next 20,from current: %s\n", buf);
	
	int size = lseek(fd, 0, SEEK_END);
	printf("file size:%d\n", size);

    close(fd);
    return 0;
}
