/*******************************************************************
 *   > File Name: 17-array.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月08日 星期二 16时16分01秒
 ******************************************************************/

#include <stdio.h>

const int MAX=3;

int main(int argc, char* argv[])
{
    int var[3] = {10, 100, 1000};
    int i;

    for(i = 0; i< MAX; i++)
    {
        printf("Value of var[%d] = %d\n", i, var[i]);
    }

    return 0;
}
