/*******************************************************************
 *   > File Name: 02-GDB_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 11:38:35 PM CST
 ******************************************************************/

#include <stdio.h>

/* 子函数add：将自然数从1～m相加 */
int add(int m)
{
    int i, n =0;
    for(i = 1; i <= m; i++)
        n += i;
    printf("The sun of 1-%d in add is %d\n", m,n);
}

int main(void)
{
    int i,n = 0;
    add(50);
    for(i = 1; i<=50; i++)
        n += i;
    printf("The sum of 1-50 is %d \n",n);
    return 0;
}
