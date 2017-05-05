/*******************************************************************
 *   > File Name: 41-valFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 05:07:37 PM CST
 ******************************************************************/

#include <stdio.h>

int fun1(int a, int b){
    return (a+b);
}

void fun(int (*p)(int, int), int a, int b){
    printf("%d + %d = %d\n", a, b, p(a,b));
}

int main(int argc, char* argv[])
{
    int x,y;
    x = 20;
    y = 50;

    fun(fun1, x, y);

    return 0;
}
