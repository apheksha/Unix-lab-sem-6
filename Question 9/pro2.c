#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char buf[21];
    int n;

    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    n = read(fd, buf, 20);
    buf[n] = '\0';
    printf("First 20 chars: %s\n", buf);

    lseek(fd, 10, SEEK_SET);
    n = read(fd, buf, 20);
    buf[n] = '\0';
    printf("20 chars from 10th byte: %s\n", buf);

    lseek(fd, 10, SEEK_CUR);
    n = read(fd, buf, 20);
    buf[n] = '\0';
    printf("20 chars from current+10: %s\n", buf);

    off_t size = lseek(fd, 0, SEEK_END);
    printf("File size: %ld bytes\n", (long)size);

    close(fd);
    return 0;
}
