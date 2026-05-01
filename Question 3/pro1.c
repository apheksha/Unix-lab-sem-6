#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    DIR *d;
    struct dirent *p;
    char path[100];
    int fd;
    int size;

    d = opendir(argv[1]);

    while((p = readdir(d)) != NULL)
    {
        if(strcmp(p->d_name,".")==0 || strcmp(p->d_name,"..")==0)
            continue;

        sprintf(path,"%s/%s",argv[1],p->d_name);

        fd = open(path,O_RDONLY);

        size = lseek(fd,0,SEEK_END);

        if(size==0)
        {
            unlink(path);
            printf("Removed empty file: %s\n",path);
        }

        close(fd);
    }

    closedir(d);
}
