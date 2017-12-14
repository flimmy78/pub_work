/*******************************************************************
 *   > File Name: 04-constForPointer2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 06:54:42 AM PST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 100, b = 300;
    const int *const p = &a;//const 将p和*p都变为只读数据

    //*p = 200;//err
    //p = &b;//err
    printf("a = %d\n", a);

    return 0;
}
