/*******************************************************************
 *   > File Name: 10-operation.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 26 15:50:02 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 21;
    int b = 10;
    int c;

    printf("The value of a and b is %d, %d\n", a,b);
    c = a + b;
    printf("The value of (a + b) is : %d\n", c);

    c = a - b;
    printf("The value of (a - b) is : %d\n", c);

    c = a * b;
    printf("The value of (a * b) is : %d\n", c);

    c = a / b;
    printf("The value of (a / b) is : %d\n", c);

    c = a % b;
    printf("The value of (a %% b) is : %d\n", c);

    c = a ++;
    printf("The value of (a ++ ) is : %d\n", c);

    c = a --;
    printf("The value of (a -- ) is : %d\n", c);


    return 0;
}
