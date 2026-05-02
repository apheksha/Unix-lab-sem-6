#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    int i;
    char *type;

    if(argc < 2)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++)
    {
        if(lstat(argv[i], &st) == -1)
        {
            perror(argv[i]);
            continue;
        }

        if (S_ISREG(st.st_mode))      type = "regular file";
        else if (S_ISDIR(st.st_mode)) type = "directory";
        else if (S_ISLNK(st.st_mode)) type = "symbolic link";
        else if (S_ISCHR(st.st_mode)) type = "character special file";
        else if (S_ISBLK(st.st_mode)) type = "block special file";
        else if (S_ISFIFO(st.st_mode)) type = "FIFO / pipe";
        else if (S_ISSOCK(st.st_mode)) type = "socket";
        else                           type = "unknown file type";

        printf("%s: %s\n", argv[i], type);
    }

    return 0;
}
