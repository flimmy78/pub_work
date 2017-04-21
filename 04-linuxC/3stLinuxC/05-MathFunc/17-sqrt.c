/*******************************************************************
 *   > File Name: 17-sqrt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 05:39:28 PM CST
 ******************************************************************/
#if (0)
double sqrt(double x);
//计算平方根值；
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double value = 0.0;
    double answer = 0.0;
    int res;

    while(1){
        fflush(stdin);
        printf("Pls input a double integer :");
        if((res = scanf("%lf", &value)) != 1){
            printf("Input err, res = %d\n", res);continue;
        }

        answer = sqrt(value);
        printf("sqrt(%lf) = %lf\n", value, answer);
    }


    return 0;
}
