/*******************************************************************
 *   > File Name: static.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 03:53:31 PM CST
 ******************************************************************/

#include <stdio.h>

void func(void);

static int count = 5;

int main(int argc, char* argv[])
{
    while(count --){
        func();
    }

    return 0;
}

void func(void){
    static int i = 5;
    i ++;

    printf("i is %d and count is %d\n", i, count);
}
