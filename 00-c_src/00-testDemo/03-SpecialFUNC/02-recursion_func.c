/*******************************************************************
 *   > File Name: 02-recursion_func.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 10:48:52 PM CST
 ******************************************************************/

#include <stdio.h>

void fun(int n);

int main(void)
{
    fun(5);
    return 0;
}

void fun(int n)
{
    printf("n = %d\n",n);
    n--;
    if(n > 0)
        fun(n);
}
