/*******************************************************************
 *   > File Name: 60-sizeofStruct.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Nov 16 09:05:45 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    struct A{
        int a;
        char b;
        float c;
        char d[10];
    }a;

    printf("sizeof a = %d\n", sizeof a);

    return 0;
}
