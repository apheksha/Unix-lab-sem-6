// Write a C program to illustrate the effect of setjmp and longjmp functions on register and volatile variables.

#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;

int global_var;

void jump_function()
{
    longjmp(buf,1);
}

void display(int auto_var,int reg_var,int vol_var,int static_var)
{
    printf("Inside Function:\n");
    printf("%d %d %d %d %d\n",global_var,auto_var,reg_var,vol_var,static_var);

    jump_function();
}

int main()
{
    int auto_var;
    register int reg_var;
    volatile int vol_var;
    static int static_var;

    global_var=1;
    auto_var=2;
    reg_var=3;
    vol_var=4;
    static_var=5;

    if(setjmp(buf)!=0)
    {
        printf("After longjmp:\n");
        printf("%d %d %d %d %d\n",global_var,auto_var,reg_var,vol_var,static_var);
        return 0;
    }

    global_var=95;
    auto_var=96;
    reg_var=97;
    vol_var=98;
    static_var=99;

    display(auto_var,reg_var,vol_var,static_var);

    return 0;
}
