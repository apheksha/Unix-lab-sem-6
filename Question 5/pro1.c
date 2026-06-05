// Write a program to copy access and modification time of a file to another file using utime function.

#include<stdio.h>
#include<sys/stat.h>
#include<utime.h>

int main(int argc,char *argv[])
{
    struct stat st;
    struct utimbuf timebuf;

    if(argc!=3)
    {
        printf("Usage: %s <sourcefile> <destinationfile>\n",argv[0]);
        return 1;
    }

    if(stat(argv[1],&st)==-1)
    {
        perror("stat");
        return 1;
    }

    timebuf.actime=st.st_atime;
    timebuf.modtime=st.st_mtime;

    if(utime(argv[2],&timebuf)==-1)
    {
        perror("utime");
        return 1;
    }

    printf("Time Copied Successfully\n");

    return 0;
}
