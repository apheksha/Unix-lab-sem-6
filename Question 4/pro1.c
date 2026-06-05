// Write a C program to demonstrate the creation of soft links and hard links.

#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc!=4)
    {
        printf("Usage:\n");
        printf("%s h <source> <hardlink>\n",argv[0]);
        printf("%s s <source> <softlink>\n",argv[0]);
        return 1;
    }

    if(argv[1][0]=='h')
    {
        if(link(argv[2],argv[3])==0)
            printf("Hard Link Created\n");
        else
            perror("link");
    }
    else if(argv[1][0]=='s')
    {
        if(symlink(argv[2],argv[3])==0)
            printf("Soft Link Created\n");
        else
            perror("symlink");
    }
    else
    {
        printf("Invalid Option\n");
    }

    return 0;
}
