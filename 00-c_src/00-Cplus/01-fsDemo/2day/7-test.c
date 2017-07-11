/*******************************************************************
 *   > File Name: 7-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 05:28:02 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 5, b = 3;

    printf("befor a = %d, b = %d\n",a ,b);
    //a = a + b;
    a += b;
    printf("after a = %d, b = %d\n", a, b);

    return 0;
}
