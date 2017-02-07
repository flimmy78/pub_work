/*******************************************************************
 *   > File Name: 06-rand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Feb 2017 10:19:53 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#if (0)
int rand(void);/*产生随机数*/
//返回0到RAND_MAX之间的随机数
#endif

int main(int argc, char* argv[])
{
    int value;

    value = rand();
    printf("%d\n",value);
    printf("RAND_MAX = %f\n",RAND_MAX + 1.0);

    return 0;
}
