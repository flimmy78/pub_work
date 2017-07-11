/*******************************************************************
 *   > File Name: 1-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 11:07:35 AM CST
 ******************************************************************/

#include <stdio.h>
/*INC for strlen*/
#include <string.h>

/*说明：
 *strlen:计算字符串的长度；
 *sizeof:计算字符串在内存中的长度
 * */

int main(int argc, char* argv[])
{
    int len1, len2;

    len1 = strlen("HelloWorld");
    len2 = sizeof("HelloWorld");
    printf("len1 = %d, len2 = %d\n", len1, len2);


    return 0;
}
