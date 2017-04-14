/*******************************************************************
 *   > File Name: factorial.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 05:41:15 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

double factorial(unsigned int i)
{
    if(i <= 1){
        return 1;
    }

    return (i * factorial( i - 1));
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Usage : %s <integer>\n", argv[0]);return (-1);
    }

    int a;
    a = atoi(argv[1]);
    printf("the factorial of a :%f\n", factorial(a));

    return 0;
}
