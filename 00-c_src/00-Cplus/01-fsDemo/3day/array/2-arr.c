/*******************************************************************
 *   > File Name: 2-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 02:40:22 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

/*说明：部分元素初始化
 *
 * */

int main(int argc, char* argv[])
{
    int a[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("sizeof(a) = %d\n", sizeof(a));

    char str[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str1[10] = {"hello"};
    char str2[19] = "hello";

    printf("sizeof(str) = %d\n", sizeof(str));
    printf("strlen(str) = %d\n", strlen(str));
    printf("strlen(\"hello\") = %d\n", strlen("hello"));

    return 0;
}
