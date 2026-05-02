#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main()
{
	int fd;
	pid_t pid;
	char file[20], buffer[10];
	
	printf("Enter the filename:");
	scanf("%s",file);
	fd = open(file, O_RDONLY);

	if(fd < 0)
	{
		perror("open");
		return 1;
	}

	pid = fork();

	if(pid == -1)
	{
		perror("fork");
		return 1;
	}
	else if(pid == 0)
	{
		read(fd, buffer, 5);
		buffer[5]  = '\0';

		printf("Child process: %s\n", buffer);
	}
	else{
		wait(NULL);
		read(fd,buffer,5);
		buffer[5] = '\0';
		printf("Parent process: %s\n", buffer);
	}
	close(fd);
	return 0;
}
