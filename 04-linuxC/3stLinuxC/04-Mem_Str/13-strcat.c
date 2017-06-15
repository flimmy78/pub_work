/*******************************************************************
 *   > File Name: 13-strcat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:29:50 2017
 ******************************************************************/
#if (0)
char *strcat(char *dest, const char *src);
//@FUNC:连接两字符串；
//将参数 src 字符串拷贝到参数 dest 所指的字符串尾。第
//一个参数 dest 要有足够的空间来容纳要拷贝的字符串。
//@Return:返回参数 dest 的字符串起始地址
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[30] = "string(1)";
    char b[] = "string(2)";

    printf("Before strcat() : %s\n", a);
    printf("After strcat() : %s\n", strcat(a,b));

    return 0;
}
