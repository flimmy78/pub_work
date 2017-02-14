/*******************************************************************
 *   > File Name: 07-memchr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 03:44:53 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#if (0)
#include <string.h>
void *memchr(const void *s, int c, size_t n);/*在某一内存区域内查找特定字符*/
//memchr（）从头开始搜寻s所指的内存内容前n个字节，直到发现
//第一个值为c的字节，则返回指向该字节的指针。
//如果找到指定的字节则返回该字节的指针，否则返回0。
#endif

int main(int argc, char* argv[])
{
    char *s = "012345678901234567890123456789";
    char *p;
    printf("s   :%30s\n",s);

    p = memchr(s,'5',10);
    printf("p1  :%30s\n",p);
    p = memchr(p,'0',10);
    printf("p2  :%30s\n",p);

    return 0;
}
