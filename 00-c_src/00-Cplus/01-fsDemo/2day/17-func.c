/*******************************************************************
 *   > File Name: 17-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 11:44:32 PM CST
 ******************************************************************/

#include <stdio.h>

int fun1(int a, int b);

int main(int argc, char* argv[])
{
    int a = 5, b =3;
    int s;

    s = fun1(a, b); //a,b实参
    printf("s = %d\n", s);
    printf("a = %d, b = %d\n", a,b);

    return 0;
}

int fun1(int x, int y){ //x,y是形参
    int sum;

    sum = x + y;
    x = 100;
    y = 200;
    printf("x = %d, y = %d\n", x, y);
    return sum;
}
