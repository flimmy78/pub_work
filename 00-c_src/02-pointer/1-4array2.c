/*******************************************************************
 *   > File Name: 1-4array2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 09 May 2017 05:59:19 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int array[5];
    int *p;
    int i;

    /*给数组各元素赋值*/
    for(i = 0; i < 5; i++){
        array[i] = i;
    }

    /*输出数组各元素的值*/
    for(p = &array[0]; p != &array[5]; p++){
        printf("%d\n", *p);
    }

    return 0;
}
