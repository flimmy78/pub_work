/*******************************************************************
 *   > File Name: 01-union.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jul 13 18:45:59 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    union{
        int i;
        char x[2];
    }ua;

    ua.x[0] = 10;
    ua.x[1] = 1;
    printf("%d\n", ua.i);

    return 0;
}
