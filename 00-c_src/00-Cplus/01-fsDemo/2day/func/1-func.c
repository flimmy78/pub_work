/*******************************************************************
 *   > File Name: 1-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 11:07:10 AM CST
 ******************************************************************/

#include <stdio.h>

//定义函数func1，功能：计算两个整数数据的和，并将其返回
int func1(int a, int b){
    int sum;

    sum = a + b;
    return sum;
}

int main(int argc, char* argv[])
{
    int a = 5, b = 3;
    int s;

    s = func1(a, b);
    printf("s = %d\n", s);

    return 0;
}
