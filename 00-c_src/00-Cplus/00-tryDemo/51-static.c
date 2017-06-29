/*******************************************************************
 *   > File Name: 51-static.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 11:34:49 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    static int a = 100;
    printf("a = %d\n", a);

    a = 1000;
    printf("a = %d\n", a);

    return 0;
}
