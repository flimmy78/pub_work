/*******************************************************************
 *   > File Name: 04-char.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 08:26:49 AM CST
 ******************************************************************/

#include <stdio.h>
#define NUM 255

int main(void)
{
    int i = 0;

    for(i = 0; i< NUM; i++)
    {
        printf("%c ",i);
    }
    puts("");
    return 0;
}
