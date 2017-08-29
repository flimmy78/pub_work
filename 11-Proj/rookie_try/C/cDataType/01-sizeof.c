/*******************************************************************
 *   > File Name: 01-sizeof.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Aug 22 19:26:13 2017
 ******************************************************************/

#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(unsigned char) = %d\n", sizeof(unsigned char));
    printf("sizeof(signed char) = %d\n", sizeof(signed char));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));
    printf("sizeof(signed int) = %d\n", sizeof(signed int));
    printf("sizeof(short) = %d\n", sizeof(short));
    printf("sizeof(unsigned short) = %d\n", sizeof(unsigned short));
    printf("sizeof(signed short) = %d\n", sizeof(signed short));
    puts("======================================================");
    printf("sizeof(long) = %d\n", sizeof(long));
    printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));
    printf("sizeof(long int) = %d\n", sizeof(long int));
    printf("sizeof(long long) = %d\n", sizeof(long long));
    printf("sizeof(long double) = %d\n", sizeof(long double));
    printf("sizeof(double) = %d\n", sizeof(double));
    printf("sizeof(float) = %d\n", sizeof(float));

    return 0;
}
