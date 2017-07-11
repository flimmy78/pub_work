/*******************************************************************
 *   > File Name: 9-var.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 01:47:38 PM CST
 ******************************************************************/

#include <stdio.h>

int x1 = 100;   //全局变量
int x2;
int x3;

void fun(int x){
    int x2;
    x1 = 789;
    x2 = 123;
    x3 = 456;
}

int x2 = 200;   //全局变量
int x3 = 300;

int main(int argc, char* argv[])
{
    fun(1);
    printf("in_main : x1 = %d\n", x1);
    printf("in_main : x2 = %d\n", x2);
    printf("in_main : x3 = %d\n", x3);

    return 0;
}

//int x3 = 300;   //全局变量
