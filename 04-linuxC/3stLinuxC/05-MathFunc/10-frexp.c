/*******************************************************************
 *   > File Name: 10-frexp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 04:09:01 PM CST
 ******************************************************************/
#if (0)
double frexp(double x, int *exp);
//用来将参数 x 的浮点型数切割成底数和指数。底数部分直
//接返回，指数部分则借参数 exp 指针返回，将返回值乘以 2 的 exp
//次方即为 x 的值
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int exp;
    double fraction;
    fraction = frexp(1024, &exp);

    printf("exp = %d\n", exp);
    printf("fraction = %lf\n", fraction);

    return 0;
}
