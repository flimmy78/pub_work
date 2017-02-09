/*******************************************************************
 *   > File Name: 1-2_pointer_calc.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 06 Feb 2017 10:23:47 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int hoge;
    int *hoge_p;

    /*将指向hoge的指针赋予给hoge_p*/
    hoge_p = &hoge;
    /*输出hoge_p的值*/
    printf("hoge_p..%p\n",hoge_p);
    /*给hoge_p加1*/
    hoge_p++;
    /*输出hoge_p的值*/
    printf("hoge_p..%p\n",hoge_p);
    /*输出hoge_p加3后的值*/
    printf("hoge_p..%p\n",hoge_p+3);

    return 0;
}
