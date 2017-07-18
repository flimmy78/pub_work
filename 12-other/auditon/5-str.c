/*******************************************************************
 *   > File Name: 5-str.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jul 18 20:26:30 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    char str[] = "Hello";
    char *p = str;
    int n = 10;

    printf("%d,%d,%d\n", sizeof(str), sizeof(p), sizeof(n));

    void func(char str[100]){
        ;
    }
    printf("%d\n", sizeof(str));

    return 0;
}
