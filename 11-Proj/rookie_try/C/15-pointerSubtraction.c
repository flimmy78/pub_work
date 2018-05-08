/*******************************************************************
 *   > File Name: 15-pointerSubtraction.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月08日 星期二 11时01分50秒
 ******************************************************************/

#include <stdio.h>

#if (1)
#define MAX 3
#else
const int MAX = 3;
#endif

int main(int argc, char* argv[])
{
    int var[MAX] = {10, 100, 1000};
    int i, *ptr;

    ptr = &var[MAX - 1];

    for(i = MAX; i> 0; i--)
    {
        printf("存储地址:var[%d] = %X\n", i-1, (unsigned int)ptr);
        printf("存储值： var[%d] = %d\n\n", i-1, *ptr);

        ptr--;
    }

    return 0;
}
