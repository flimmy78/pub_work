/*******************************************************************
 *   > File Name: 9-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 05:31:31 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 5, b = 3,c;
    c = (a, c = b, a += b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}
