/*******************************************************************
 *   > File Name: 08-endian.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 05:35:59 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    union{
        char c;
        int i;
    }u;

    u.i = 0x0201;

    if(u.c == 1)
        printf("little-endian\n");
    else if(u.c == 2)
        printf("big-endian \n");
    else
        printf("unknown");

    return 0;
}
