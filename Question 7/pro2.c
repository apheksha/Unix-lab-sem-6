// C program to simulate copy command by accepting filenames
// from command line and reporting errors.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int src, dest;
    char buf[1024];
    ssize_t n;

    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    src = open(argv[1], O_RDONLY);

    if (src < 0)
    {
        perror("Source File");
        return 1;
    }

    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest < 0)
    {
        perror("Destination File");
        close(src);
        return 1;
    }

    while ((n = read(src, buf, sizeof(buf))) > 0)
    {
        if (write(dest, buf, n) != n)
        {
            perror("Write Error");
            close(src);
            close(dest);
            return 1;
        }
    }

    if (n < 0)
    {
        perror("Read Error");
    }
    else
    {
        printf("File Copied Successfully\n");
    }

    close(src);
    close(dest);

    return 0;
}
