#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	mode_t oldmask;

	oldmask = umask(002);
	printf("Oldmask:%03o, New mask : 022\n", oldmask);

	int fd = creat("t1.txt",0777);

	if(fd < 0)
	{
		printf("Error creating file\n");
	       	return 1;
	}
	chmod("t1.txt",0644);
	printf("Changing permission of t1.txt to 0644\n");
	 return 0;
}
