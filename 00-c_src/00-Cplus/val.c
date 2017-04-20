/*******************************************************************
 *   > File Name: val.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 03:22:25 PM CST
 ******************************************************************/

#include <stdio.h>

/* declaration variable */
extern int a, b;
extern int c;
extern float f;

int main(int argc, char* argv[])
{
    /* define the variable */
    int a, b;
    int c;
    float f;

    /* initialize */
    a = 10;
    b = 20;

    c = a + b;
    printf("Value of c : %d\n", c);

    f = 70.0/3.0;
    printf("Value of f : %f\n", f);

    return 0;
}
