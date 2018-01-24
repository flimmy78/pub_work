/*******************************************************************
 *   > File Name: 10-hexToBin.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jan 24 10:15:58 2018
 ******************************************************************/

#include <stdio.h>

void print_bin(int x, int n);

int main(int argc, char* argv[])
{
    int x;
    printf("Input number:");
    scanf("%d", &x);

    printf("Number of decimal form :%d\n", x);
    printf("    it's binary form :");
    print_bin(x, sizeof(int)*8);
    putchar('\n');

    return 0;
}

/*输出整数X二进制形式的后n位*/
void print_bin(int x,int n){
    if(n > 0){

        /*输出第n位：先左移n-1位取值，再右移n-1位还原*/
        putchar('0' + ((unsigned)((x & (1 << (n-1))) >> (n-1))));
        if((n-1)%8 == 0){
            putchar(' ');
        }

        if((n-1)%4 == 0){
            putchar(' ');
        }
        /*递归调用*/
        print_bin(x, n -1);
    }
}
