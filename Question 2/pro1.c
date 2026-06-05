//Write a C program to display various details of a file using stat structure (At least 5 fields).
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char *argv[])
{
    struct stat s;

    if(argc!=2)
    {
        printf("Usage: %s <filename>\n",argv[0]);
        return 1;
    }

    if(stat(argv[1],&s)==-1)
    {
        perror("stat");
        return 1;
    }

    printf("File Name          : %s\n",argv[1]);
    printf("File Size          : %ld bytes\n",(long)s.st_size);
    printf("Inode Number       : %ld\n",(long)s.st_ino);
    printf("Permissions        : %o\n",s.st_mode & 0777);
    printf("Link Count         : %ld\n",(long)s.st_nlink);
    printf("Owner UID          : %d\n",s.st_uid);
    printf("Owner GID          : %d\n",s.st_gid);
    printf("Last Access Time   : %s",ctime(&s.st_atime));

    return 0;
}
