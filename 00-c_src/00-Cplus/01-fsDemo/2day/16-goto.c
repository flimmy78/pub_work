/*******************************************************************
 *   > File Name: 16-goto.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 11:17:24 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    i = 1;

A:
    if(i % 2 == 0)
        goto B;
    i++;
    printf("i = %d\n", i);
    goto A;
B:

    return 0;
}
