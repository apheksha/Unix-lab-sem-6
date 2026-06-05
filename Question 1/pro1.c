#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char ch;
    off_t size, i;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);

    if (size == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("Reverse Content:\n");

    for (i = size - 1; i >= 0; i--)
    {
        lseek(fd, i, SEEK_SET);
        read(fd, &ch, 1);
        write(STDOUT_FILENO, &ch, 1);
    }

    printf("\n");

    close(fd);

    return 0;
}
