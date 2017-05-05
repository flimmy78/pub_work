/*******************************************************************
 *   > File Name: 36-scanf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 02:27:20 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    char a[10];

    scanf("%c%c%c", &a[0], &a[1], &a[2]);
    printf("string is %c, %c, %c\n", a[0], a[1], a[2]);

    return 0;
}
