/*******************************************************************
 *   > File Name: 1-3array.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 09 May 2017 09:00:35 AM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int array[5];
    int i;

    /*为数组各元素赋值*/
    for(i = 0; i < 5; i++){
        array[i] = i;
    }

    /*输出数组各元素的值*/
    for(i = 0; i< 5; i++){
        printf("%d\n",array[i]);
    }

    /*输出数组各元素的地址*/
    for(i = 0; i< 5; i++){
        printf("array[%d]...%p\n", i, &array[i]);
    }

    return 0;
}
