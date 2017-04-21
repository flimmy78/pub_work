/*******************************************************************
 *   > File Name: 06-ceil.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 03:08:23 PM CST
 ******************************************************************/
#if (0)
double ceil(double x);
//返回不小于x的最小正整数
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double input = 0.0;
    double value = 0.0;

    while(1){
        printf("Pls input a double integer :");
        if((scanf("%lf", &input)) != 1){
            printf("Input error\n");break;
        }

        value = ceil(input);
        printf("ceil(%lf) = %lf\n", input, value);
    } 

    return 0;
}
