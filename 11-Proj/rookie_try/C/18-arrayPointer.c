/*******************************************************************
 *   > File Name: 18-arrayPointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月08日 星期二 16时27分48秒
 ******************************************************************/

#include <stdio.h>

const int MAX=3;

int main(int argc, char* argv[])
{
    int var[] = {10, 100, 1000};
    int i,*ptr[MAX];

    for(i = 0; i< MAX; i++)
    {
        ptr[i] = &var[i];
    }

    for(i = 0; i< MAX; i++)
    {
        printf("Value of var[%d] = %d\n", i, *ptr[i]);
    }

    return 0;
}
