#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp1,*fp2;
	char ch;

	if(argc != 3)
	{
		printf("Usage %s source destination:",argv[0]);
		return 1;
	}

	fp1 = fopen(argv[1],"r");

	if(fp1 == NULL)
	{
		printf("Error opening source file:");
		return 1;
	}

	fp2 = fopen(argv[2],"w");

	if(fp2 == NULL)
	{
		printf("Error creating destination file");
		return 1;
	}

	while((ch = fgetc(fp1))!=EOF)
		fputc(ch,fp2);
	printf("Copied successfully");

	fclose(fp1);
	fclose(fp2);

	return 0;
}
