/*******************************************************************
 *   > File Name: 14-pointerAddition.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月08日 星期二 10时42分16秒
 ******************************************************************/

#include <stdio.h>

const int MAX = 3;

int main(int argc, char* argv[])
{
    int var[] = {10, 100, 200};
    int i, *ptr;

    /*指针中的数组地址*/
    ptr = var;

    for(i = 0; i< MAX; i++)
    {
        printf("存储位置：var[%d] = %X\n", i, (unsigned int)ptr);
        printf("存储位置：var[%d] = %p\n", i, ptr);
        printf("存储值：var[%d] = %d\n\n", i, *ptr);

        ptr++;
    }

    return 0;
}
