/*******************************************************************
 *   > File Name: 03-IntArg.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Tue 03 Jan 2017 09:49:17 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    static int a1 = 123;
    const int a2 = 0123;
    static int a3 = 0x123;

    printf("a1 = %d\n",a1);
    printf("a2 = %d\n",a2);
    printf("a3 = %d\n",a3);

    a1 = 456;
    //a2 = 789;   // error: assignment of read-only variable ‘a2’
    a3 = a2;

    return 0;
}
