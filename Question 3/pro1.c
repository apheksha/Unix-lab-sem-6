#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    DIR *d;
    struct dirent *p;
    char path[100];
    int fd;
    off_t size;

    if(argc != 2){
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    d = opendir(argv[1]);
    if(d == NULL){
        perror("opendir");
        return 1;
    }

    while((p = readdir(d)) != NULL){
        if(strcmp(p->d_name,".") == 0 || strcmp(p->d_name,"..") == 0)
            continue;

        sprintf(path,"%s/%s",argv[1],p->d_name);

        fd = open(path,O_RDONLY);
        if(fd < 0)
            continue;

        size = lseek(fd,0,SEEK_END);

        if(size == 0){
            if(unlink(path) == 0)
                printf("removed empty :%s\n",path);
            else
                perror("unlink");
        }

        close(fd);
    }

    closedir(d);
    return 0;
}
