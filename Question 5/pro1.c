#include<stdio.h>
#include<sys/stat.h>
#include<utime.h>
#include<stdlib.h>

int main()
{
    char file1[100], file2[100];
    struct stat s;
    struct utimbuf t;

    printf("Enter source file: ");
    scanf("%s", file1);

    printf("Enter destination file: ");
    scanf("%s", file2);

    if(stat(file1, &s) == -1)
    {
        perror("stat");
        return 1;
    }

    t.actime = s.st_atime;
    t.modtime = s.st_mtime;

    if(utime(file2, &t) == -1)
    {
        perror("utime");
        return 1;
    }

    printf("Time copied successfully\n");

    return 0;
}
