/*******************************************************************
 *   > File Name: 2_printf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 10:18:45 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a;
    float b;
    double c;

    a = 123;
    b = 23.45;
    c = 123.456;

    printf("a = %d, b = %f, c = %f\n", a, b, c);
    printf("a = %d, b = %f\n", 100,102.456);

    printf("a = %d\n", 100+300);
    printf("%s\n","Hello");
    printf("%%\n");


    return 0;
}
