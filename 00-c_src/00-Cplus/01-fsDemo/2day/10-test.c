/*******************************************************************
 *   > File Name: 10-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 05:43:46 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a ;

    printf("sizeof(double) = %d\n", sizeof(double));
    //printf("sizeof double = %d\n", sizeof double);//err
    printf("sizeof(a) = %d\n", sizeof(a));  //ok
    printf("sizeof a = %d\n", sizeof a);    //ok

    return 0;
}
