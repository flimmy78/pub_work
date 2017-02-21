/*******************************************************************
 *   > File Name: 09-memmove.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Feb 2017 05:12:31 PM CST
 ******************************************************************/
#if (0)
#include <string.h>

void *memmove(void *dest, const void *src, size_t n);
//memmove（）与 memcpy（）一样都是用来拷贝 src 所指的内存内
//容前 n 个字节到 dest 所指的地址上。不同的是，当 src 和 dest 所指
//的内存区域重叠时，memmove（）仍然可以正确的处理，不过执行
//效率上会比使用 memcpy（）略慢些
////return :返回指针dest
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
