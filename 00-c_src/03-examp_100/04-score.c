/*******************************************************************
 *   > File Name: 04-score.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Oct 2017 10:22:10 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int integer, i, max, min, sum;
    max = -32768;   /*先假设当前最大值max为C语言整型数的最小值*/
    min = 32767;    /*先假设当前最小值min为C语言整型数的最大值*/
    sum = 0;        /*将累计求和变量的初值置为0*/

    for(i = 1; i <= 10; i++){
        printf("Input number %d = ", i);
        scanf("%d", &integer);  /*输入评分*/
        sum += integer;         /*计算总分*/
        if(integer > max)       /*通过比较筛选出其中的最高分*/
            max = integer;
        if(integer < min)       /*通过比较筛选出其中的最低分*/
            min = integer;
    }

    printf("Canceled max score :%d\nCanceled min score :%d\n", max, min);
    printf("Average score :%d\n", (sum - max - min) / 8);   /*输出结果*/

    return 0;
}
