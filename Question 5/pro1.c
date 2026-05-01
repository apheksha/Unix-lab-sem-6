#include<stdio.h>
#include<sys/stat.h>
#include<utime.h>

int main()
{
    char file1[20], file2[20];
    struct stat s;
    struct utimbuf t;

    printf("Enter source file: ");
    scanf("%s", file1);

    printf("Enter destination file: ");
    scanf("%s", file2);

    stat(file1, &s);

    t.actime = s.st_atime;
    t.modtime = s.st_mtime;

    utime(file2, &t);

    printf("Time copied successfully\n");

    return 0;
}
