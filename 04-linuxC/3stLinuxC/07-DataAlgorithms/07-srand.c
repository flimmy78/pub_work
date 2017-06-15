/*******************************************************************
 *   > File Name: 06-srand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 17:16:21 2017
 ******************************************************************/
#if (0)
void srand(unsigned int seed);//设置随机数种子
int rand(void);
//用来设置 rand（）产生随机数时的随机数种子。参数 seed
//必须是个整数，通常可以利用 geypid（）或 time（0）的返回值来
//当做 seed。如果每次 seed 都设相同值，rand（）所产生的随机数值
//每次就会一样
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRand(void){
    int i,j;

    srand((int)time(NULL));

    for(i = 0; i< 10; i++){
        j = 1 + (int)(10.0*rand()/(RAND_MAX + 1.0));
        printf("%d ", j);
    }
    puts("");
}

int main(int argc, char* argv[])
{
    int k;

    for(k = 0; k < 10; k++){
        printRand();
        sleep(1);
    }

    return 0;
}
