/*******************************************************************
 *   > File Name: 33-val.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 10:17:09 AM CST
 ******************************************************************/

#include <stdio.h>

void fun2(int *a, int *b){
    *a *= 2;
    *b *= 3;
}

int main(int argc, char* argv[])
{
    int x, y;
    x = 100;
    y = 200;
    printf("%s :x = %d, y = %d\n", __func__, x, y);
    fun2(&x, &y);   /*地址传递*/
    printf("After fun2 :x = %d, y = %d\n", x, y);

    return 0;
}
