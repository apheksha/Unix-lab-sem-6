#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if(argc == 4 && argv[1][0] == 'h')
    {
        if(link(argv[2], argv[3]) == 0)
            printf("Hard link created\n");
        else
            perror("link");
    }
    else if(argc == 4 && argv[1][0] == 's')
    {
        if(symlink(argv[2], argv[3]) == 0)
            printf("Soft link created\n");
        else
            perror("symlink");
    }
    else
    {
        printf("Usage:\n");
        printf("%s h <source> <hardlink>\n", argv[0]);
        printf("%s s <source> <softlink>\n", argv[0]);
    }

    return 0;
}
