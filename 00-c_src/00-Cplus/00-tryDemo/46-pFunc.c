/*******************************************************************
 *   > File Name: 46-pFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 06 May 2017 03:42:12 PM CST
 ******************************************************************/

#include <stdio.h>

typedef void(*TYPE)(void);

void fun(void){
    printf("Hello world\n");
}

TYPE fun1(void){
    return fun;
}

int main(int argc, char* argv[])
{
    void (*p)(void);

    p = fun1();
    p();

    return 0;
}
