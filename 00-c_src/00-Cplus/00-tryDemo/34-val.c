/*******************************************************************
 *   > File Name: 34-val.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 10:26:55 AM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int *a, int *b){
    scanf("%d%d", a,b);
}

void fun2(int *a, int *b){
    *a *= 2;
    *b *= 3;
}

int main(int argc, char* argv[])
{
    int x, y;

    fun1(&x, &y);
    printf("x = %d,y = %d\n", x, y);
    fun2(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
