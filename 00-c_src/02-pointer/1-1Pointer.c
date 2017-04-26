/*******************************************************************
 *   > File Name: 1-1Pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 26 Apr 2017 02:19:17 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int hoge = 5;
    int piyo = 10;
    int  *hoge_p;

    /*input the variable*/
    printf("hoge....%d\n", hoge);
    printf("piyo....%d\n", piyo);
    printf("hoge_p....%p\n\n",hoge_p);

    /*input the addr of variable*/
    printf("&hoge....%p\n", &hoge);
    printf("&piyo....%p\n", &piyo);
    printf("&hoge_p....%p\n\n", &hoge_p);

    /*将hoge的地址赋给hoge_p*/
    hoge_p = &hoge;
    printf("hoge_p....%p\n", hoge_p);

    /*通过hoge_p输出hoge*/
    printf("*hoge_p....%d\n", *hoge_p);

    /*通过hoge_p修改hoge的内容*/
    *hoge_p = 10;
    printf("hoge....%d\n\n",hoge);


    return 0;
}
