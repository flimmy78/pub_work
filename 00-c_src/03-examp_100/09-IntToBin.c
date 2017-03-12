/*******************************************************************
 *   > File Name: 09-IntToBin.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 11 Mar 2017 04:41:08 PM CST
 ******************************************************************/
#if (0)
//将任意整数转化为二进制
#endif

#include <stdio.h>

void printb(int x , int n){
    if(n > 0){
        putchar('0' + ((unsigned)(x & (1 << (n - 1)))) >> (n - 1));
        printb(x, n-1);
    }
}

int main(int argc, char* argv[])
{
    int x;

    printf("Input integer:");
    scanf("%d",&x);
    printf("number of decimal form:%d\n",x);
    printb(x, sizeof(int) * 8);
    putchar('\n');

    return 0;
}
