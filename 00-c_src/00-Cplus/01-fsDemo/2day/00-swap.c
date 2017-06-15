/*******************************************************************
 *   > File Name: 00-swap.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 09:59:16 2017
 ******************************************************************/

#include <stdio.h>

void swap(int a, int b){
    printf("a= %d, b= %d\n",a,b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a= %d, b= %d\n",a,b);
}

int main(int argc, char* argv[])
{

    int a = 10, b = 100;
    int c = 500, d = 999;

    printf("Before swap c= %d, d= %d\n",c,d);
    swap(c,d);
    printf("After swap c= %d, d= %d\n",c,d);


    printf("a= %d, b= %d\n",a,b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a= %d, b= %d\n",a,b);

    return 0;
}
