/*******************************************************************
 *   > File Name: 03-asin.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 02:17:54 PM CST
 ******************************************************************/
#if (0)
double asin(double x);
//@func:计算反余弦值，然后将结果返回。参数范围为-1到1之间，超过范围
//则会失败
//返回-PI/2&PI/2之间的值
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double angle = 0.0;
    double value = 0.0;

    while(1){
        printf("Pls input a double integer (-1 ~ 1) :");
        if((scanf("%lf", &angle)) != 1){
            printf("Input error\n");break;
        }
        if((angle > 1) || (angle < -1)){
            printf("Iput param too large\n");break;
        }

        value = asin(angle);
        printf("asin(%lf) = %lf\n", angle, value);
    }

    return 0;
}
