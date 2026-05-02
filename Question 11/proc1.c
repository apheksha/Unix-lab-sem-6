#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int fd, fd_dup, fd_dup2;

    fd = open("dup_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) { perror("open"); return 1; }

    fd_dup = dup(fd);
    printf("Original fd = %d\n", fd);
    printf("dup fd      = %d (lowest available)\n", fd_dup);

    fd_dup2 = dup2(fd, 10);
    printf("dup2 fd     = %d (fixed descriptor 10)\n", fd_dup2);

    write(fd,      "Written using original fd\n", 26);
    write(fd_dup,  "Written using dup fd\n", 21);
    write(fd_dup2, "Written using dup2 fd\n", 22);

    close(fd);
    close(fd_dup);
    close(fd_dup2);

    return 0;
}
