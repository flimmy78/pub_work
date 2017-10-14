/*******************************************************************
 *   > File Name: align.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 05:15:23 PM CST
 ******************************************************************/

#include <stdio.h>

struct param{
    char a;
    short b;
    int c;
};

struct param1{
    char a;
    int b;
    short c;
};

int main(int argc, char* argv[])
{
    struct param p1;
    printf("sizeof(struct param) = %d\tsizeof p1 = %d\n", sizeof(struct param), sizeof p1);

    struct param1 p2;
    printf("sizeof(struct param1) = %d\tsizeof p2 = %d\n", sizeof(struct param1), sizeof p2);

    return 0;
}
