// Write a C program to implement ls -li command which lists the files in a specified directory. Your program should print 5 attributes of files.

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char buf[500];
    char *path;

    path=(argc==2)?argv[1]:".";

    dir=opendir(path);

    if(dir==NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("INODE\tPERM\tLINKS\tUID\tGID\tFILE\n");

    while((entry=readdir(dir))!=NULL)
    {
        sprintf(buf,"%s/%s",path,entry->d_name);

        if(stat(buf,&st)==-1)
            continue;

        printf("%ld\t%o\t%ld\t%d\t%d\t%s\n",
               (long)st.st_ino,
               st.st_mode & 0777,
               (long)st.st_nlink,
               st.st_uid,
               st.st_gid,
               entry->d_name);
    }

    closedir(dir);

    return 0;
}
