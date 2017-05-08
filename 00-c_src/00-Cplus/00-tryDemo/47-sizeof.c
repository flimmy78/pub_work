/*******************************************************************
 *   > File Name: 47-sizeof.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 09:59:59 AM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#define STR "xxxx-xx-xx_xx:xx:xx"

int main(int argc, char* argv[])
{
    int ret;
    ret = sizeof(STR);
    printf("ret = %d\n", ret);
    ret = strlen(STR);
    printf("ret = %d\n", ret);

    return 0;
}
