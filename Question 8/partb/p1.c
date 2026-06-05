// Child program used by parent process to demonstrate access() function.

#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: %s <filename>\n",argv[0]);
        return 1;
    }

    if(access(argv[1],F_OK)==0)
        printf("File Exists\n");
    else
        printf("File Does Not Exist\n");

    if(access(argv[1],R_OK)==0)
        printf("Read Permission : YES\n");

    if(access(argv[1],W_OK)==0)
        printf("Write Permission : YES\n");

    if(access(argv[1],X_OK)==0)
        printf("Execute Permission : YES\n");

    return 0;
}
