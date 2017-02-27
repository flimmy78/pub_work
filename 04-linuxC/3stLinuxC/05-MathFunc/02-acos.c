/*******************************************************************
 *   > File Name: 02-acos.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 11:31:34 AM CST
 ******************************************************************/
#if (0)
#include <math.h>
double acos(double x);/*取反余弦函数*/
//acos () 用来计算参数 x 的反余弦值，然后将结果返回。参数 x 范
//围为－1 至 1 之间，超过此范围则会失败。
//返回 0 至 PI 之间的计算结果，单位为弧度，在函数库中角度均以
//弧度来表示
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double angle;
    angle = acos(0.5);
    printf("angle = %f\n",angle);
    return 0;
}
