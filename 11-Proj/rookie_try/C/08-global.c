/*******************************************************************
 *   > File Name: 08-global.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 26 15:33:31 2017
 ******************************************************************/

#include <stdio.h>

void func1(void);

static int count = 10;

int main(int argc, char* argv[])
{
    while(count --){
        func1();
    }

    return 0;
}

void func1(void)
{
    static int thingy = 5;
    thingy ++;
    printf("Thingy 为%2d， count为 %2d\n", thingy, count);
}
