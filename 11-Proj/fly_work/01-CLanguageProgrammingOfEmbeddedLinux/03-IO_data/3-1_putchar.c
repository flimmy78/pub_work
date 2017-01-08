/*******************************************************************
 *   > File Name: 3-1_putchar.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sun 08 Jan 2017 09:48:52 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int a = 65;
    char b = 'B';

    putchar(a);
#if (1)
    putchar('\n');
    putchar(b);
    putchar('\n');
#endif

    return 0;
}
