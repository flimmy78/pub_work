/*******************************************************************
 *   > File Name: 06-memccpy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 03:15:32 PM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
void *memccpy(void *dest, const void *src, int c, size_t n);/*拷贝内存内容*/
//memccpy（）用来拷贝src 所指的内存内容前n 个字节到dest 所指
//的地址上。与memcpy（）不同的是，memccpy（）会在复制时检
//查参数c是否出现，若是则返回dest中值为c的下一个字节地址。
//返回指向dest 中值为c 的下一个字节指针。返回值为0 表示在src
//所指内存前n个字节中没有值为c的字节。
#endif

int main(int argc, char* argv[])
{
    char a[] = "STRINGR(a)";
    char b[] = "stringr(b)";
    printf("a :%s\nb :%s\n",a,b);

    memccpy(a, b, 'r',sizeof b);
    printf("memccpy() :%s\n",a);

    return 0;
}
