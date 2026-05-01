#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat s;
    int i;

    if(argc < 2)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++)
    {
        if(lstat(argv[i], &s) == -1)
        {
            printf("%s: Error\n", argv[i]);
            continue;
        }

        if(S_ISREG(s.st_mode))
            printf("%s: regular\n", argv[i]);
        else if(S_ISDIR(s.st_mode))
            printf("%s: directory\n", argv[i]);
        else if(S_ISLNK(s.st_mode))
            printf("%s: symbolic link\n", argv[i]);
        else
            printf("%s: other\n", argv[i]);
    }

    return 0;
}
