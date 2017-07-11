/*******************************************************************
 *   > File Name: 19-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 11:59:58 PM CST
 ******************************************************************/

#include <stdio.h>

void fun(int x){
    printf("x = %d\n", x);
}

int main(int argc, char* argv[])
{
    fun(100);
    fun(3+5);

    return 0;
}
