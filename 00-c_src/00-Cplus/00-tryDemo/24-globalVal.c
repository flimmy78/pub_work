/*******************************************************************
 *   > File Name: 24-globalVal.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Mar 2017 01:06:37 PM CST
 ******************************************************************/

#include <stdio.h>

int x1 = 100;   /*全局变量*/
int x2;
int x3;

void fun(int x){
    int x2 = 123;
    printf("in_fun :x1 = %d\n", x1);
    printf("in_fun :x2 = %d\n", x2);//x2不再是全局变量
    printf("in_fun :x3 = %d\n", x3);
}

int x2 = 200;//全局变量

int main(int argc, char* argv[])
{
    fun(1);
    printf("in_main :x1 = %d\n",x1);
    printf("in_main :x2 = %d\n",x2);
    printf("in_main :x3 = %d\n",x3);
    return 0;
}

int x3 = 300;//全局变量
