/*******************************************************************
 *   > File Name: 1-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 11:04:47 AM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6};   //完全初始化
    printf("sizeof(a) = %d\n", sizeof(a));

    char str[] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '\0'};
    printf("%s\n", str);

    char s[] = "hello";
    printf("%s\n", s);
    printf("sizeof(s) = %d\n", sizeof(s));

    return 0;
}
