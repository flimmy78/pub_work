/*******************************************************************
 *   > File Name: 06-memchr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 12:29:49 2017
 ******************************************************************/
#if (0)
void *memchr(const void *s, int c, size_t n);
//@FUNC:在某一内存范围中查找一特定字符；
//从头开始搜寻 s 所指的内存内容前 n 个字节，直到发现
//第一个值为 c 的字节，则返回指向该字节的指针。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *s = "0123456790124567901234567980";
    char *p;

    p = memchr(s, '5', 10);
    printf("%s\n", p);

    return 0;
}
