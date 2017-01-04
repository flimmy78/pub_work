/*******************************************************************
 *   > File Name: 05-DataType.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 04 Jan 2017 01:16:29 PM CST
 ******************************************************************/

#include <stdio.h>

#define BUFSIZE 20
#define DATATYPE 13

char D_Type[DATATYPE][BUFSIZE] ={
    "char",
    "unsigned char",
    "short",
    "unsigned short",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "float",
    "double",
    "long int",
    "long long",
    "long double"
};
int main(void)
{
    printf("ret = %d\n",sizeof(D_Type));
    return 0;
}

