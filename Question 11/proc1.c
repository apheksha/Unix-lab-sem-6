// Write a program to differentiate between dup and dup2 functions.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd;
    int fd_dup;
    int fd_dup2;

    fd=open("test.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);

    if(fd<0)
    {
        perror("open");
        return 1;
    }

    fd_dup=dup(fd);

    fd_dup2=dup2(fd,10);

    printf("Original FD : %d\n",fd);
    printf("dup FD      : %d\n",fd_dup);
    printf("dup2 FD     : %d\n",fd_dup2);

    write(fd,"Using Original FD\n",18);
    write(fd_dup,"Using dup FD\n",13);
    write(fd_dup2,"Using dup2 FD\n",14);

    close(fd);
    close(fd_dup);
    close(fd_dup2);

    return 0;
}
