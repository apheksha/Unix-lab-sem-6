// Write a C program to perform the following operations:
// i. To read the first 20 characters from a file
// ii. seek to 10th byte from the beginning and display 20 characters from there
// iii. seek 10 bytes ahead from the current file offset and display 20 characters
// iv. Display the file size

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd;
    int n;
    char buf[21];
    off_t size;

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

    n=read(fd,buf,20);
    buf[n]='\0';
    printf("First 20 Characters : %s\n",buf);

    lseek(fd,10,SEEK_SET);

    n=read(fd,buf,20);
    buf[n]='\0';
    printf("From 10th Byte : %s\n",buf);

    lseek(fd,10,SEEK_CUR);

    n=read(fd,buf,20);
    buf[n]='\0';
    printf("Current + 10 : %s\n",buf);

    size=lseek(fd,0,SEEK_END);

    printf("File Size : %ld Bytes\n",(long)size);

    close(fd);

    return 0;
}
