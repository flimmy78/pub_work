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

void printb(int x, int n){
    if(n > 0){
        putchar('0' + ((x&(1 << (n - 1))) >> (n - 1)));
        if((n - 1) % 4 == 0)
            putchar(' ');
        printb(x, n - 1);
    }else if(n == 0)
        puts("");
}

void printb_r(int x){
    int i;

    for(i = sizeof(int)*8 ; i > 0; i --){
        putchar('0' + ((x&(1 << (i - 1))) >> (i - 1)));
        if((i - 1) % 8 == 0)
            putchar(' ');
    }
    puts("");
}

#if (0)
char *printb_rs(int x, int n){
    static char str[n] = {0};
    static int i = 0, j = 0;

    for(i = n, j = 0; i > 0, j < n; i --, j++){
        str[j] = '0' + ((x&(1 << (i - 1))) >> (i - 1));
    }
    str[j] = '\0';
    return str;
}
#endif

int main(int argc, char *argv[])
{
#if (0)
    printb_r(0xFFFFFFF);
    printb(0xFFFFFFF,32);
#endif
#if (0)
    if(argc > 2 || argc < 2){
        printf("\n\t\tUsage :%s  <Integer>\n", argv[0]);return (-1);
    }

    int n;
    n = atoi(argv[1]);
    printb(n, sizeof(int)*8);
#endif
    printf("%s\n", printb_rs(15, 32));
    return 0;
}
