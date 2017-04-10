/*******************************************************************
 *   > File Name: 98-sizeof.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 03:48:14 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
#if (0)
    struct test{
        int a;
        char b[10];
    };
#else
#pragma pack(push)
#pragma pack(1)
    struct test{
        int a;
        char b[10];
    };
#pragma pack(pop)
#endif

    struct test c;
    printf("sizeof(c) = %d\n", sizeof(c));
    printf("sizeof c = %d\n", sizeof c);
    printf("sizeof(struct test) = %d\n", sizeof(struct test));
    printf("sizeof(int) = %d\n", sizeof(int));
    //printf("sizeof int = %d\n", sizeof int);//error

    return 0;
}
