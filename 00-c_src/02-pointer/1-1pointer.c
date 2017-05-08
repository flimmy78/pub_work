/*******************************************************************
 *   > File Name: 1-1pointer.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Mon May  8 14:11:13 2017
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int hoge = 5;
    int piyo = 10;
    int *hoge_p;
    
    /*output the value of every variable*/
    printf("hoge.....%d\n", hoge);
    printf("piyo.....%d\n", piyo);
    printf("hoge_p...%p\n\n", hoge_p);

    /*output the address of every variable(Val)*/
    printf("&hoge.....%p\n", &hoge);
    printf("&piyo.....%p\n", &piyo);
    printf("&hoge_p...%p\n\n", &hoge_p);

    /*将hoge地址赋给hoge_p*/
    hoge_p = &hoge;
    printf("hoge_p.....%p\n", hoge_p);

    /*通过hoge_p输出hoge的内容*/
    printf("*hoge_p...%d\n", *hoge_p);

    /*通过hoge_p修改hoge的内容*/
    *hoge_p = 10;
    printf("hoge......%d\n", hoge);

    return 0;
}
