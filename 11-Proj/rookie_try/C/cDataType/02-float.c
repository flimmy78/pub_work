/*******************************************************************
 *   > File Name: 02-float.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Aug 22 19:38:46 2017
 ******************************************************************/

#include <stdio.h>
#include <float.h>

int main(int argc, char* argv[])
{
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("the min value of float :%E\n", FLT_MIN);
    printf("the max valeu of float :%E\n", FLT_MAX);
    printf("the digit of float :%d\n", FLT_DIG);

    return 0;
}
