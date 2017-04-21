/*******************************************************************
 *   > File Name: 09-exp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 03:55:01 PM CST
 ******************************************************************/
#if (0)
double exp(double x);
//返回e的x次方的结果
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double input = 0.0;
    double value = 0.0;

    while(1){
        printf("Pls input a double integer:");
        if((scanf("%lf", &input)) != 1){
            printf("Input err\n");break;
        }

        value = exp(input);
        printf("exp(%lf) = %lf\n", input, value);
    }

    return 0;
}
