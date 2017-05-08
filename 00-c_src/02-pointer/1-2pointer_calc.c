/*******************************************************************
 *   > File Name: 1-2pointer_calc.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Mon May  8 15:35:53 2017
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int hoge;
    int *hoge_p;

    /*将指向hoge的指针赋予hoge_p*/
    hoge_p = &hoge;
    /*输出hoge的值*/
    printf("hoge_p..%p\n", hoge_p);
    /*给hoge_p加1*/
    hoge_p ++;
    /*输出hoge_p的值*/
    printf("hoge_p..%p\n", hoge_p);
    /*输出hoge_p的值*/
    printf("hoge_p..%p\n", hoge_p + 3);

    return 0;
}
