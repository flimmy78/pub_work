/*******************************************************************
 *   > File Name: 06-memory5b.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 24 Apr 2017 06:04:26 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    char z = *(char *)0;
    printf("I read from location zero :%c\n", z);

    return 0;
}
