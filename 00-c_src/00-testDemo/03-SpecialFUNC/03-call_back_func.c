/*******************************************************************
 *   > File Name: 03-call_back_func.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 11:06:32 PM CST
 ******************************************************************/

#include <stdio.h>

void fun(void);
void print(void(*p)(void));

int main(void)
{
    print(fun);

    return 0;
}

void fun(void) //回调函数
{
    printf("Hello world !\n");
}

void print(void(*p)(void))
{
    p();
}
