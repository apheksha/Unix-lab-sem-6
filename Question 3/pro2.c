#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *d;
	struct stat m;
	char *dir;
	char path[100];

	dir = (argc > 1) ? argv[1] : ".";
	dp = opendir(dir);

	if(dp == NULL)
	{
		printf("Cannot open directory");
		return 0;
	}

	while((d = readdir(dp)) != NULL)
	{
		sprintf(path, "%s%s", dir, d->d_name);
		stat(path,&m);

		printf("%ld %o %d %d %s %s\n", m.st_ino, m.st_mode, m.st_uid, m.st_gid, ctime(&m.st_atime),d->d_name);
	}
	closedir(dp);
	return 0;
}
