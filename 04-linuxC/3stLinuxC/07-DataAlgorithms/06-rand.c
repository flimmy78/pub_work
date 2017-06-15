/*******************************************************************
 *   > File Name: 06-rand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 17:11:02 2017
 ******************************************************************/
#if (0)
int rand(void);//产生随机数
//回一随机数值，范围在 0 至 RAND_MAX 间。在调用
//此函数产生随机数前，必须先利用 srand（）设好随机数种子，如
//果未设随机数种子，rand（）在调用时会自动设随机数种子为 1。
//关于随机数种子请参考 srand（）。
//返回 0 至 RAND_MAX 之间的随机数值，RAND_MAX 定义在
//stdlib.h，其值为 2147483647
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int i,j;

    for(i = 0; i<10; i++){
        j = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));
        printf("%d ", j);
    }
    printf("\n");

    return 0;
}
