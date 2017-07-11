/*******************************************************************
 *   > File Name: 8-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 05:30:14 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 5, b = 3, c;

    c = a < b ? a : b;
    printf("c = %d\n", c);

    return 0;
}
