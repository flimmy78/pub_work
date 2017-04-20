/*******************************************************************
 *   > File Name: operator2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 04:36:04 PM CST
 ******************************************************************/

#include <stdio.h>

main()
{
    int a = 21;
    int b = 10;
    int c ;

    c = a + b;
    printf("Line 1 - c 的值是 %d\n", c );
    c = a - b;
    printf("Line 2 - c 的值是 %d\n", c );
    c = a * b;
    printf("Line 3 - c 的值是 %d\n", c );
    c = a / b;
    printf("Line 4 - c 的值是 %d\n", c );
    c = a % b;
    printf("Line 5 - c 的值是 %d\n", c );
    c = a++; 
    printf("Line 6 - c 的值是 %d\n", c );
    c = a--; 
    printf("Line 7 - c 的值是 %d\n", c );

}
