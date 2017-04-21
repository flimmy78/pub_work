/*******************************************************************
 *   > File Name: 15-sin.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 05:19:38 PM CST
 ******************************************************************/
#if (0)
double sin(double x);
//计算正弦值
#endif

#include <stdio.h>
#include <math.h>

//#define CONTINUE

int main(int argc, char* argv[])
{
    double value = 0.0;
    double answer = 0.0;

    while(1){
        printf("Pls input a double integer:");
        if((scanf("%lf", &value)) != 1){
#ifdef CONTINUE
            printf("Input err\n");break;
#else
            printf("Input err\n");continue;
#endif
        }

        answer = sin(value);
        printf("sin(%lf) = %lf\n", value, answer);
    }

    return 0;
}
