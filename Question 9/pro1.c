// Write a C program to demonstrate the usage of umask and chmod functions.

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int fd;
    mode_t mask;
    struct stat st;

    mask=umask(002);

    printf("Old Umask : %03o\n",mask);

    fd=creat("test.txt",0777);

    if(fd<0)
    {
        perror("creat");
        return 1;
    }

    close(fd);

    stat("test.txt",&st);
    printf("Before chmod : %o\n",st.st_mode & 0777);

    if(chmod("test.txt",0644)==-1)
    {
        perror("chmod");
        return 1;
    }

    stat("test.txt",&st);
    printf("After chmod : %o\n",st.st_mode & 0777);

    return 0;
}
