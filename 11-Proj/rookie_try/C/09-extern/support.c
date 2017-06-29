/*******************************************************************
 *   > File Name: support.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 26 15:46:26 2017
 ******************************************************************/

#include <stdio.h>

extern int count;

void write_extern(void)
{
    printf("count is %d\n", count);
}

