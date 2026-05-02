#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd,n;
    struct flock f;
    char file[100], buf[51];
    off_t size;

    printf("Enter file name: ");
    scanf("%s", file);

    fd = open(file, O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    if(size < 100)
    {
        printf("File too small\n");
        return 1;
    }

    f.l_type = F_WRLCK;
    f.l_whence = SEEK_SET;
    f.l_start = size - 100;
    f.l_len = 100;

    if(fcntl(fd, F_GETLK, &f) == -1)
    {
        perror("fcntl");
        return 1;
    }

    if(f.l_type != F_UNLCK)
    {
        printf("Locked by PID: %d\n", f.l_pid);
        close(fd);
        return 0;
    }

    f.l_type = F_WRLCK;
    if(fcntl(fd, F_SETLK, &f) == -1)
    {
        perror("lock");
        return 1;
    }

    printf("Region locked. Press Enter to continue...\n");
    getchar(); getchar();

    lseek(fd, size - 50, SEEK_SET);
    n = read(fd, buf, 50);
    buf[n] = '\0';

    printf("%s\n", buf);

    f.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f);

    printf("Region unlocked\n");

    close(fd);
    return 0;
}
