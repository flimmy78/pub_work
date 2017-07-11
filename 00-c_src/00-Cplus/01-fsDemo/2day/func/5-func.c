/*******************************************************************
 *   > File Name: 5-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 11:40:05 AM CST
 ******************************************************************/

#include <stdio.h>

void fun(int x){
    printf("x = %d\n", x);
}

int main(int argc, char* argv[])
{
    fun(100);   //传递常量
    fun(3 + 5); //传递表达式

    return 0;
}
