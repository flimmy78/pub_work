/*******************************************************************
 *   > File Name: 01-char.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 11:05:10 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *c1 = "abc";
    char c2[] = "abc";
    char *c3 = (char*)malloc(3);

    c3 = "abc";
    printf("%p %p %s\n",&c1,c1,c1);
    printf("%p %p %s\n",&c2,c2,c2);
    printf("%p %p %s\n",&c3,c3,c3);

    return 0;
}
