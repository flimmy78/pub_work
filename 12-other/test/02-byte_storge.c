/*******************************************************************
 *   > File Name: 01-byte_storge.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Jul 2017 09:18:52 AM CST
 ******************************************************************/

#include <stdio.h>

struct A{
    char a;
    int b;
    short c;
}st1;

struct B{
    char a;
    short c;
    int b;
}st2;

int main(int argc, char* argv[])
{
    printf("%d\t%d\n", sizeof(st1), sizeof(st2));

    return 0;
}
