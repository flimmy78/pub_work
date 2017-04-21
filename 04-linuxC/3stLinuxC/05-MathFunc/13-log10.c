/*******************************************************************
 *   > File Name: 13-log10.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 04:39:22 PM CST
 ******************************************************************/
#if (0)
double log10(double x);
//计算以10为底的对数值
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double value = 0.0;
    double answer = 0.0;

    while(1){
        printf("Pls input a double integer :");
        if((scanf("%lf", &value)) != 1){
            printf("Input err\n");break;
        }

        answer = log10(value);
        printf("log10(%lf) = %lf\n", value, answer);
    }

    return 0;
}
