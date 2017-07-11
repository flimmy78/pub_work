/*******************************************************************
 *   > File Name: 3-printf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 01:56:31 PM CST
 ******************************************************************/

#include <stdio.h>

void printf_test(void){
    char ch = 'A';
    short a1 = 100;
    int a = 123;
    long a2 = 200;
    long long a3 = 123456;
    float b = +5.6;
    float c = -5.6;

    printf("%-5d\n", a);
    printf("%05d\n", a);
    printf("%+f\n", b);
    printf("%f\n",c);
    printf("%.2f\n", b);
    printf("%d, %hd, %ld\n", a, a1, a2);
    printf("%hhd\n", ch);
    printf("%lld\n", a3);
}

int main(int argc, char* argv[])
{
    printf_test();

    return 0;
}
