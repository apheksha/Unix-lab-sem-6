// Write a program to read n characters from a file and append them back to the same file using dup2 function.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int fd;
    int n;
    int count;
    char buf[100];

    if(argc!=3)
    {
        printf("Usage: %s <filename> <n>\n",argv[0]);
        return 1;
    }

    fd=open(argv[1],O_RDWR);

    if(fd<0)
    {
        perror("open");
        return 1;
    }

    n=atoi(argv[2]);

    count=read(fd,buf,n);

    if(count<0)
    {
        perror("read");
        return 1;
    }

    buf[count]='\0';

    lseek(fd,0,SEEK_END);

    dup2(fd,1);

    write(1,buf,strlen(buf));

    close(fd);

    return 0;
}
