#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *d;
    struct stat m;
    char *dir;
    char path[200];

    dir = (argc > 1) ? argv[1] : ".";

    dp = opendir(dir);
    if(dp == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("Inode\tMode\tUID\tGID\tAccess Time\t\tFile Name\n");

    while((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dir, d->d_name);

        if(stat(path, &m) == -1)
        {
            perror("stat");
            continue;
        }

        printf("%ld\t%o\t%d\t%d\t%s\t%s\n",
               (long)m.st_ino,
               m.st_mode & 0777,
               (int)m.st_uid,
               (int)m.st_gid,
               ctime(&m.st_atime),
               d->d_name);
    }

    closedir(dp);
    return 0;
}
