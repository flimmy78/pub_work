/*******************************************************************
 *   > File Name: 01-printf.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 31 Dec 2016 12:10:37 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int a;
    float b;
    double c;

    a = 100;
    b = 123.456;
    c = 1234.5678;

    printf(" a = %5d , b = %f , c = %f\n",a,b,c);
    printf(" a= %d , b = %f\n",999,1.999);
    printf(" a = %d\n",11+55);
    printf("%s\n","HelloWorld");
    printf("%%\n");

    char ch = 'A';
    short a1 = 100;
    int a2 = 123;
    long a3 = 200;
    long long a4 = 123456;
    float b1 = +5.6;

    printf("%05d\n",a2);
    printf("%+f\n",b1);
    printf("%.2f\n",b1);
    printf("%hd , %d , %ld\n",a1,a2,a3);
    printf("%hhd\n",ch);
    printf("%lld\n",a4);

    return 0;
}
