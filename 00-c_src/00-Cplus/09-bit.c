/*******************************************************************
 *   > File Name: 09-bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 05:38:33 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    union u
    {
        struct {
            char i:1;
            char j:2;
            char m:3;
        }s;
        char c;
    }r;

    r.s.i = 1;  //1
    r.s.j = 2;  //10
    r.s.m = 3;  //011
    printf("%d\t0x%x\n",r.c,r.c);

    return 0;
}
