/*******************************************************************
 *   > File Name: 1_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 09:51:10 2017
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int len1, len2;

    len1 = strlen("HelloWorld");    //字符串的长度
    len2 = sizeof("HelloWorld");    //字符串在内存中的长度
    printf("len1 = %d, len2 = %d\n", len1,len2);

    return 0;
}
