/*******************************************************************
 *   > File Name: operator.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 04:09:22 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{   
    int a = 21;
    int b = 10;
    int c;
    
    printf("a value :%d  b value :%d\n", a, b);

    c = a + b;
    printf("LINE1 - (a + b)=c value :%d\n", c);

    c = a - b;
    printf("LINE2 - (a - b)=c value :%d\n", c);

    c = a * b;
    printf("LINE3 - (a * b)=c value :%d\n", c);

    c = a / b;
    printf("LINE4 - (a / b)=c value :%d\n", c);

    c = a % b;
    printf("LINE5 - (a %% b)=c value :%d\n", c);

    c = a++;
    printf("LINE6 - (a++)=c value :%d  a value :%d\n", c, a);

    c = a--;
    printf("LINE7 - (a--)=c value :%d  a value :%d\n", c, a);

    return 0;
}
