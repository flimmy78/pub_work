/*******************************************************************
 *   > File Name: 11-ldexp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 04:18:28 PM CST
 ******************************************************************/
#if (0)
double ldexp(double x, int exp);
//用来将参数 x 乘上 2 的 exp 次方值，即 x*2exp。
//返回计算结果
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int exp = 2;
    double x = 3,answer;
    answer = ldexp(x ,exp);
    printf("3*2^(2) = %lf\n", answer);

    return 0;
}
