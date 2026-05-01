#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	char file[20], ch;
	int fd,size,i;
	printf("Enter the filename:");
	scanf("%s", file);
	fd = open(file,O_RDONLY);

	if(fd < 0){
		printf("File not found");
		return 0;
	}
	size = lseek(fd, 0, SEEK_END);
	printf("Reverse Content:\n");
	
	for(int i=size-1; i>=0;i--){
		lseek(fd, i, SEEK_SET);
		read(fd, &ch, 1);
		printf("%c", ch);
	}
	close(fd);
}
