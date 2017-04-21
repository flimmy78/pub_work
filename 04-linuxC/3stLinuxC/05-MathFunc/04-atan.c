/*******************************************************************
 *   > File Name: 04-atan.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 02:46:42 PM CST
 ******************************************************************/
#if (0)
double atan(double x);
//@FUNC:取反正切值
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double angle = 0.0;
    double value = 0.0;

    while(1){
        printf("Pls input a interge :");
        if((scanf("%lf", &angle)) != 1){
            printf("Input error\n");break;
        }

        value = atan(angle);
        printf("atan(%lf) = %lf\n", angle, value);
    }

    return 0;
}
