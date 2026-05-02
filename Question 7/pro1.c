#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int gv = 95;
static int sv = 99;

void f1()
{
    int av = 96;
    register int rv = 97;
    volatile int vv = 98;

    printf("Before setjmp:\n");
    printf("gv=%d av=%d rv=%d vv=%d sv=%d\n", gv, av, rv, vv, sv);

    if(setjmp(buf) == 0)
    {
        gv = 100;
        av = 200;
        rv = 300;
        vv = 400;
        sv = 500;

        longjmp(buf, 1);
    }
    else
    {
        printf("After longjmp:\n");
        printf("gv=%d av=%d rv=%d vv=%d sv=%d\n", gv, av, rv, vv, sv);
    }
}

int main()
{
    f1();
    return 0;
}
