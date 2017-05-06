/*******************************************************************
 *   > File Name: 44-pFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 06 May 2017 02:30:43 PM CST
 ******************************************************************/

#include <stdio.h>

int xy = 123;

int *fun(void){
    return &xy;
}

int main(int argc, char* argv[])
{
    int *p;

    p = fun();
    printf("*p = %d\n", *p);

    return 0;
}
