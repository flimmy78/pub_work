/*******************************************************************
 *   > File Name: 10-bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 05:41:34 PM CST
 ******************************************************************/

#include <stdio.h>

union{
    struct
    {
        unsigned char a1:2;
        unsigned char a2:3;
        unsigned char a3:3;
    }x;
    unsigned char b;
}d;

int main(void)
{
    d.b = 100;  //100 == 0110 0100

    printf("0x%x\n0x%x\n0x%x\n",d.x.a1, d.x.a2, d.x.a3);

    return 0;
}
