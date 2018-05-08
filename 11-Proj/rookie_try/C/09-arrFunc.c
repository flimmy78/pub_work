/*******************************************************************
 *   > File Name: 09-arrFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月24日 星期二 20时30分56秒
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*生成 10 个随机数，并使用数组来返回它们*/
int *getRandom()
{
    static int r[10];
    int i;

    srand((unsigned)time(NULL));

    for(i = 0; i< 10; i++)
    {
        r[i] = rand();
        printf("r[%d] = %d\n", i, r[i]);
    }

    return r;
}

int main(int argc, char* argv[])
{
    int *p;
    int i;

    p = getRandom();
    for(i = 0; i< 10; i++)
    {
        printf("*(p + %d) : %d\n", i, *(p + i));
    }

    return 0;
}
