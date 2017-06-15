/*******************************************************************
 *   > File Name: 22-strncat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 17:06:30 2017
 ******************************************************************/
#if (0)
char *strncat(char *dest, const char *src, size_t n);
//将参数 src 字符串拷贝 n 个字符到参数 dest 所指的字
//符串尾。第一个参数 dest 要有足够的空间来容纳要拷贝的字符串。
//返回参数 dest 的字符串起始地址。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[30] = "string(1)";
    char b[] = "STRING[2]";

    printf("before strncat() :%s\n", a);
    printf("after strncat() :%s\n", strncat(a, b, 6));

    return 0;
}
