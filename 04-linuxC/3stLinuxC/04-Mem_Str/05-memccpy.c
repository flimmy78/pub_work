/*******************************************************************
 *   > File Name: 05-memccpy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 11:48:11 2017
 ******************************************************************/
#if (0)
void *memccpy(void *dest, const void *src, int c, size_t n);
//@FUNC:复制内存区域：拷贝 src 所指的内存内容前 n 个字节到 dest 所指
//的地址上。与 memcpy（）不同的是，memccpy（）会在复制时检
//查参数 c 是否出现，若是则返回 dest 中值为 c 的下一个字节地址。
//@RETURN：返回指向 dest 中值为 c 的下一个字节指针。返回值为 0 表示在 src
//返回值 所指内存前 n 个字节中没有值为 c 的字节
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[] = "string[a]";
    char b[] = "stirng(b)";

    memccpy(a, b, 'B', sizeof(b));
    printf("memccpy() :%s\n", a);


    return 0;
}
