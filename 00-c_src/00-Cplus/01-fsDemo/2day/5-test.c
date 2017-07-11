/*******************************************************************
 *   > File Name: 5-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 02:21:06 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define AND &&
#define OR  ||

int main(int argc, char* argv[])
{
    bool a;
    a = !4;
    printf("a = %d\n", a);

    int b = 5;
    if(a < b && (a = 100)){
        printf("farsight\n");
    }else{
        printf("It is false\n");
    }

    printf("a = %d, b = %d\n", a, b);

    a = 5, b = 3;
    if(a > b OR (a = 100)){
        printf("内部语句\n");
    }else{
        printf("False, a = %d, b = %d\n", a, b);
    }
    printf("a = %d , b = %d\n", a, b);

    return 0;
}
