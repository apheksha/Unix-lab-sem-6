#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>

static jmp_buf buf;
static int gv;

void f2(void){
    longjmp(buf,1);
}

void f1(int av,int rv,int vv,int sv){
    printf("In f1:\n");
    printf("gv=%d av=%d rv=%d vv=%d sv=%d\n",gv,av,rv,vv,sv);
    f2();
}

int main(){
    int av;
    register int rv;
    volatile int vv;
    static int sv;

    gv=1; av=2; rv=3; vv=4; sv=5;

    if(setjmp(buf)!=0){
        printf("After longjmp:\n");
        printf("gv=%d av=%d rv=%d vv=%d sv=%d\n",gv,av,rv,vv,sv);
        return 0;
    }

    gv=95; av=96; rv=97; vv=98; sv=99;

    f1(av,rv,vv,sv);
    return 0;
}
