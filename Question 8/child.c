#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage %s source destination");
		return 1;
	}

	if(access(argv[1],F_OK) == 0)
		printf("File '%s' exists and can be accessed.\n", argv[1]);
	else
		printf("File '%s' doesnot exist and cannot be accessed.\n", argv[1]);

	return 0;
}

