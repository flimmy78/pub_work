/*******************************************************************
 *   > File Name: 14-pow.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 05:03:48 PM CST
 ******************************************************************/
#if (0)
double pow(double x, double y);
//计算次方值，return the value of x raised to the power of y
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double value1 = 0.0;
    double value2 = 0.0;
    double answer = 0.0;

    while(1){
        printf("Pls input two double integers :");
        if((scanf("%lf %lf", &value1, &value2)) != 2){
            printf("Input err\n");break;
        }
        answer = pow(value1, value2);
        
        printf("pow(%lf , %lf) = %lf\n", value1, value2, answer);
    }

    return 0;
}
