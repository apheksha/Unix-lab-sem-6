#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    mode_t oldmask;

    oldmask = umask(002);
    printf("Old mask: %03o\n", oldmask);

    int fd = creat("t1.txt",0777);

    if(fd < 0)
    {
        perror("creat");
        return 1;
    }

    printf("File created\n");

    if(chmod("t1.txt",0644) < 0)
    {
        perror("chmod");
        return 1;
    }

    printf("Permissions changed to 0644\n");

    return 0;
}
