#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
	int fd,n;
	char f1[100],b[51];
	struct flock f;
	off_t s;
	printf("Enter file name: ");
	scanf("%s",f1);
	fd=open(f1,O_RDWR);

	s=lseek(fd,0,SEEK_END);

	f.l_type=F_WRLCK;
	f.l_whence=SEEK_SET;
	f.l_start=s-100;
	f.l_len=100;

	fcntl(fd,F_GETLK,&f);
	if(f.l_type!=F_UNLCK) {
		printf("Locked by PID: %d\n",f.l_pid);
		return 0;
	}

	f.l_type=F_WRLCK;
	fcntl(fd,F_SETLK,&f);

	printf("Region locked. Press Enter to continue...\n");
	getchar();
	getchar();

	lseek(fd,s-50,SEEK_SET);
	n=read(fd,b,50);
	b[n]='\0';
	printf("%s\n",b);

	f.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&f);

	printf("Region unlocked\n");
}
