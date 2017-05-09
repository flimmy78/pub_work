/*******************************************************************
 *   > File Name: 05-memory5b.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 05:50:55 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char z = *(const char *)0;//取出零地址处的数据,error
    printf("I read from location zero %c\n", z);

    return 0;
}
