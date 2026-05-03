#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *p;
    struct stat s;
    char *dir;
    char path[200];

    dir = (argc > 1) ? argv[1] : ".";

    d = opendir(dir);
    if(d == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("Inode\tMode\tUID\tGID\tAccess Time\t\tFile Name\n");

    while((p = readdir(d)) != NULL)
    {
        sprintf(path, "%s/%s", dir, p->d_name);

        if(stat(path, &s) == -1)
        {
            perror("stat");
            continue;
        }

        printf("%ld\t%o\t%d\t%d\t%s\t%s\n",
               (long)s.st_ino,
               s.st_mode & 0777,
               (int)s.st_uid,
               (int)s.st_gid,
               ctime(&s.st_atime),
               p->d_name);
    }

    closedir(d);
    return 0;
}
