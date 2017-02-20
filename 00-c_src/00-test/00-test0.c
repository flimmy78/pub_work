/*******************************************************************
 *   > File Name: 00-test0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 09 Jan 2017 01:57:06 PM CST
 ******************************************************************/

#include <stdio.h>

typedef struct _DATA_STR
{
    char* data;
    int len;
}DATA_STR;

int main(void)
{
    int ret;

    ret = sizeof(DATA_STR);
    printf("ret = %d\n",ret);
    return 0;
}
