/*******************************************************************
 *   > File Name: 16-pointerCompare.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月08日 星期二 15时33分54秒
 ******************************************************************/

#include <stdio.h>

const int MAX = 3;

int main(int argc, char* argv[])
{
    int var[] = {10, 100, 1000};
    int i, *ptr;

    ptr = var;
    i = 0;

    while(ptr <= &var[MAX - 1])
    {
        printf("Address of var[%d] = %x\n", i, (unsigned int)ptr);
        printf("Value   of var[%d] = %d\n", i, *ptr);


        ptr ++;
        i++;
    }

    return 0;
}
