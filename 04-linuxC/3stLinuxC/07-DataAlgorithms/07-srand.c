/*******************************************************************
 *   > File Name: 07-srand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 11:43:58 AM CST
 ******************************************************************/
#if (0)
void srand(unsigned int seed);/*设置随机数种子*/
//srand() 用来设置 rand（）产生随机数时的随机数种子。参数 seed
//必须是个整数，通常可以利用 geypid（）或 time（0）的返回值来
//当做 seed。如果每次 seed 都设相同值，rand（）所产生的随机数值
//每次就会一样。
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int i,j;

    /*产生1到10之间的随机数值*/
    srand((int)time(NULL));


    return 0;
}
