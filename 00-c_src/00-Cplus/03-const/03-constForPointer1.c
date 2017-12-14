/*******************************************************************
 *   > File Name: 03-constForPointer1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 06:49:22 AM PST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 100, b = 300;
    int * const p = &a;//cosnt将p变为只读数据

    *p = 200;
    //p = &b;
    printf("a = %d\n", a);

    return 0;
}
