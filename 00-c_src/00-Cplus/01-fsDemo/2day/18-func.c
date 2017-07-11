/*******************************************************************
 *   > File Name: 18-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 11:57:24 PM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int* x, int* y){
    *x = 100;
    *y = 200;
}

int main(int argc, char* argv[])
{
    int a = 5, b = 3;

    printf("a = %d, b = %d\n", a, b);
    fun1(&a, &b);   //地址传递
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
