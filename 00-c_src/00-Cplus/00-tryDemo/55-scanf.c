/*******************************************************************
 *   > File Name: 55-scanf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Oct 19 13:33:58 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a,b;

    while(~scanf("%d%d", &a, &b))
        printf("a + b = %d\n", a+b);

    return 0;
}
