#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat s;
    int i;
    char *type;

    if(argc < 2)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++)
    {
        if(lstat(argv[i], &s) == -1)
        {
            perror(argv[i]);
            continue;
        }

        if (S_ISREG(s.st_mode))       type = "regular file";
        else if (S_ISDIR(s.st_mode))  type = "directory";
        else if (S_ISLNK(s.st_mode))  type = "symbolic link";
        else if (S_ISCHR(s.st_mode))  type = "character special file";
        else if (S_ISBLK(s.st_mode))  type = "block special file";
        else if (S_ISFIFO(s.st_mode)) type = "FIFO / pipe";
        else if (S_ISSOCK(s.st_mode)) type = "socket";
        else                          type = "unknown file type";

        printf("%s: %s\n", argv[i], type);
    }

    return 0;
}}
