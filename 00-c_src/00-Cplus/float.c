/*******************************************************************
 *   > File Name: float.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 02:49:31 PM CST
 ******************************************************************/

#include <stdio.h>
#include <float.h>

int main(int argc, char* argv[])
{
    printf("float 存储最大字节数：%d\n", sizeof(float));
    printf("float 最小值：%E--->%f\n", FLT_MIN, FLT_MIN);
    printf("float 最大值：%E--->%f\n", FLT_MAX, FLT_MIN);
    printf("精度值：%d\n", FLT_DIG);
    return 0;
}
