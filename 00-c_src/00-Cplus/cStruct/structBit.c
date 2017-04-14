/*******************************************************************
 *   > File Name: structBit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 01:46:08 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    }bit, *pbit;

    bit.a = 1;  /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b = 7;
    bit.c = 15;

    printf("%d, %d, %d\n", bit.a, bit.b, bit.c);
    pbit = &bit;
    pbit->a = 0;
    pbit->b &= 3;   //0111&0011 = 0011
    pbit->c |= 3;   //1111|0011 = 1111
    printf("%d, %d, %d\n", pbit->a, pbit->b, pbit->c);

    return 0;
}
