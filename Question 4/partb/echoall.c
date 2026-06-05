// Write a C program:
// i. To create a child process.
// ii. The child should execute an interpreter file by passing a few arguments.
// iii. Create an interpreter file that has the path of echoall.c file and pass one argument.
// iv. Create echoall.c file which prints the arguments received from both child process and interpreter file.

#include<stdio.h>

int main(int argc,char *argv[])
{
    int i;

    printf("Arguments Received:\n");

    for(i=0;i<argc;i++)
    {
        printf("argv[%d] = %s\n",i,argv[i]);
    }

    return 0;
}
