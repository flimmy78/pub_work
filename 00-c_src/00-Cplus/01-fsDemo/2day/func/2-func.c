/*******************************************************************
 *   > File Name: 2-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 11:20:19 AM CST
 ******************************************************************/

#include <stdio.h>

int fun1(int a, int b); //函数声明

int main(int argc, char* argv[])
{
    int a = 5, b = 3;
    int s;

    s = fun1(a, b);
    printf("s = %d\n", s);

    return 0;
}

int fun1(int a, int b){
    int sum;

    sum = a + b;
    return sum;
}
