#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    int fd;
    pid_t pid;
    char buf[6];

    if(argc!=2)
    {
        printf("Usage: %s <filename>\n",argv[0]);
        return 1;
    }

    fd=open(argv[1],O_RDONLY);

    if(fd<0)
    {
        perror("open");
        return 1;
    }

    pid=fork();

    if(pid<0)
    {
        perror("fork");
        return 1;
    }

    if(pid==0)
    {
        read(fd,buf,5);
        buf[5]='\0';

        printf("Child Read : %s\n",buf);
        printf("Child Offset : %ld\n",(long)lseek(fd,0,SEEK_CUR));
    }
    else
    {
        wait(NULL);

        read(fd,buf,5);
        buf[5]='\0';

        printf("Parent Read : %s\n",buf);
        printf("Parent Offset : %ld\n",(long)lseek(fd,0,SEEK_CUR));
    }

    close(fd);

    return 0;
}
