#include<stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
    int i;

    printf("Arguments:\n");
    for(i=0;i<argc;i++)
        printf("argv[%d]=%s\n", i, argv[i]);

    printf("\nEnvironment variables:\n");
    for(i=0; environ[i]!=NULL; i++)
        printf("%s\n", environ[i]);

    return 0;
}
