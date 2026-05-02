#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char file[100], buf[100];
    int fd, n, r;

    printf("Enter the filename: ");
    scanf("%s", file);

    printf("Enter n: ");
    scanf("%d", &n);

    fd = open(file, O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    r = read(fd, buf, n);
    if(r < 0)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buf[r] = '\0';

    lseek(fd, 0, SEEK_END);

    dup2(fd, 1);   

    write(1, buf, strlen(buf));

    close(fd);
    return 0;
}
