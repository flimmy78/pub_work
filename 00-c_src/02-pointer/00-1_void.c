/*******************************************************************
 *   > File Name: 00-1_void.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 06 Feb 2017 10:05:35 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int hoge = 5;
    int* hoge_p;

    hoge_p = &hoge; /*这里不报错*/
    printf("%d\n",*(int*)hoge_p);/*打印输出hoge_p指向的变量的值*/

    return 0;
}
