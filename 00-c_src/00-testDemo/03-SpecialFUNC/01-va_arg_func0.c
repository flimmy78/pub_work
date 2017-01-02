/*******************************************************************
 *   > File Name: 01-va_arg_func0.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 10:54:01 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdarg.h>

void myprintf(int n,...);

int main(void)
{   
    myprintf(5, 10, 11, 12, 13, 14);
    myprintf(7, 10, 11, 12, 13, 14, 15, 16);

    return 0;
}

//n为要打印的整数的个数
void myprintf(int n,...)
{
    va_list p;
    int i;

    va_start(p,n);
    for(i = 0; i < n; i++)
        printf("%d\t",va_arg(p,int));
    printf("\n");
    va_end(p);
}
