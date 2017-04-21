/*******************************************************************
 *   > File Name: 12-log.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 04:25:10 PM CST
 ******************************************************************/
#if (0)
double log(double x);
//return the natural logarithm of x
//用来计算以 e 为底的 x 对数值，然后将结果返回
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double answer = 0.0;
    double value = 0.0;

    while(1){
        printf("Pls input a double integer :");
        if((scanf("%lf", &value)) != 1){
            printf("Input err\n");break;
        }

        answer = log(value);
        printf("log(%lf) = %lf\n", value, answer);
    }

    return 0;
}
