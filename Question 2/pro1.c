#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
	struct stat s;
	char file[20];

	printf("Enter the filename:");
	scanf("%s",file);

	if(stat(file, &s) == -1)
	{
		printf("File not found");
		return 0;
	}

	printf("\nFile Name         :  %s\n", file);
	printf("File Size         : %ld bytes\n", (long)s.st_size);
	printf("Inode number : %ld\n", (long)s.st_ino);
	printf("Permissions       : %o\n" , s.st_mode & 0777);
	printf("Number of links   : %ld\n", (long)s.st_nlink);
	printf("Owner UID         : %d\n", s.st_uid);
	printf("Owner GID         : %d\n", s.st_gid);
	printf("Last Access Time  : %s",ctime(&s.st_atime));

	return 0;
}
