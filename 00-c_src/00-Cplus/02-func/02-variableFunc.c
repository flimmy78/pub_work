/*******************************************************************
 *   > File Name: 02-variableFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 09:44:31 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdarg.h>

void myprint(int n, ...){
    va_list p;
    int i;

    va_start(p,n);

    for(i = 0; i < n; i++){
        printf("%d\t", va_arg(p, int));
    }
    printf("\n");

    va_end(p);
}

int main(int argc, char* argv[])
{
    myprint(5, 10, 11, 12, 13, 14);
    myprint(7, 10, 11, 12, 13, 14, 15, 16);

    return 0;
}
