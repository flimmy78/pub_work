/*******************************************************************
 *   > File Name: 02-float.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 23 11:23:24 2017
 ******************************************************************/

#include <stdio.h>
#include <float.h>

int main(int argc, char* argv[])
{
    printf("float 存储最大字节数: %lu\n", sizeof(float));
    printf("float 最小值: %E\n", FLT_MIN);
    printf("float 最大值: %E\n", FLT_MAX);
    printf("精度值: %d\n", FLT_DIG);

    return 0;
}
