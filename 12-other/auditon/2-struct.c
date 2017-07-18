/*******************************************************************
 *   > File Name: 2-struct.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jul 13 18:48:06 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    struct A{
        char c1;
        short s1;
        char c2;
        float f1;
        double d1;
    };

    printf("%lu\n", sizeof(struct A));

    return 0;
}
