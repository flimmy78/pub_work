/*******************************************************************
 *   > File Name: 01-va_arg_func.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Wed 28 Dec 2016 02:36:38 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdarg.h>

double average(int num,...);

int main(void)
{
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
    return 0;
}

double average(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum/num;
}

