/*******************************************************************
 *   > File Name: 03-callbackFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 10:17:05 AM CST
 ******************************************************************/

#include <stdio.h>

void callback_fun(void){
    printf("%s :Hello world!\n", __FUNCTION__);
}

void print(void(*p)(void)){
    p();
}

int main(int argc, char* argv[])
{
    print(callback_fun);
    return 0;
}
