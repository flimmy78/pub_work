/*******************************************************************
 *   > File Name: struct_bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Aug 11 12:55:22 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    }bit, *pbit;

    bit.a = 1;
    bit.b = 7;
    bit.c = 15;

    printf("%d, %d, %d\n", bit.a, bit.b, bit.c);
    pbit = &bit;
    pbit -> a = 0;
    pbit -> b &= 3;
    pbit -> c |= 1;
    printf("%d, %d, %d\n", pbit -> a, pbit -> b, pbit -> c);

    return 0;
}
