#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    char file[100], ch;
    int fd;
    off_t size, i;

    printf("Enter the filename: ");
    scanf("%s", file);

    fd = open(file, O_RDONLY);

    if(fd < 0){
        perror("open");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    if(size < 0){
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("Reverse Content:\n");

    for(i = size - 1; i >= 0; i--){
        lseek(fd, i, SEEK_SET);
        if(read(fd, &ch, 1) != 1){
            perror("read");
            close(fd);
            return 1;
        }
        printf("%c", ch);
    }

    printf("\n");
    close(fd);
    return 0;
}
