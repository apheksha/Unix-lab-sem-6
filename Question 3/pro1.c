// Write a C program to remove empty files from the given directory.

#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char buf[500];

    if(argc!=2)
    {
        printf("Usage: %s <directory>\n",argv[0]);
        return 1;
    }

    dir=opendir(argv[1]);

    if(dir==NULL)
    {
        perror("opendir");
        return 1;
    }

    while((entry=readdir(dir))!=NULL)
    {
        if(strcmp(entry->d_name,".")==0 ||
           strcmp(entry->d_name,"..")==0)
            continue;

        sprintf(buf,"%s/%s",argv[1],entry->d_name);

        if(stat(buf,&st)==-1)
            continue;

        if(S_ISREG(st.st_mode) && st.st_size==0)
        {
            if(unlink(buf)==0)
                printf("Removed : %s\n",buf);
        }
    }

    closedir(dir);

    return 0;
}
