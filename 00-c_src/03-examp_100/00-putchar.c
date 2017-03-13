/*******************************************************************
 *   > File Name: 00-putchar.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 09:20:44 AM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int ret;

    ret = putchar((int)'A');
    printf("ret = %d\n",ret);

    return 0;
}
