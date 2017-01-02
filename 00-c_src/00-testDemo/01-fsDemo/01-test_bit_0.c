/*******************************************************************
 *   > File Name: 01-test_bit_0.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 31 Dec 2016 10:53:55 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    char a = 5, b = 3;

    printf("a = %hhd\n",a);
    printf("a = %hhd\n",b);
    printf("~a = %hhd\n",~a);
    printf("a | b = %hhd\n",a|b);
    printf("a & b = %hhd\n",a&b);
    printf("a << 2 = %hhd\n",a<<2);
    printf("-a << 2 = %hhd\n",-a<<2);
    printf("a >> 2 = %hhd\n",a>>2);
    printf("-a >> 2 = %hhd\n",-a>>2);
    printf("a ^ b = %hhd\n",a^b);

    return 0;
}
