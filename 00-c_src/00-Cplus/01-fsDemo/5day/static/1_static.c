/*******************************************************************
 *   > File Name: 1_static.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Feb 24 18:07:32 2018
 ******************************************************************/

#include <stdio.h>

extern void fun1(int, int);

int main(int argc, char* argv[])
{
    int a,b;

    printf("Pls input two number(a, b):");
    scanf("%d,%d", &a, &b);
    fun1(a,b);

    return 0;
}
