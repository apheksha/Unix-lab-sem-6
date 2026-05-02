#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1,*fp2;
    int ch;

    if(argc != 3)
    {
        printf("Usage: %s source destination\n",argv[0]);
        return 1;
    }

    fp1 = fopen(argv[1],"r");
    if(fp1 == NULL)
    {
        perror("Source file");
        return 1;
    }

    fp2 = fopen(argv[2],"w");
    if(fp2 == NULL)
    {
        perror("Destination file");
        return 1;
    }

    while((ch = fgetc(fp1)) != EOF)
        fputc(ch,fp2);

    printf("Copied successfully\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
