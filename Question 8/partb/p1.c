#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    if(access(argv[1], F_OK) == 0)
        printf("File exists\n");
    else
        printf("File does not exist\n");

    if(access(argv[1], R_OK) == 0)
        printf("Read permission: YES\n");
    if(access(argv[1], W_OK) == 0)
        printf("Write permission: YES\n");
    if(access(argv[1], X_OK) == 0)
        printf("Execute permission: YES\n");

    return 0;
}
