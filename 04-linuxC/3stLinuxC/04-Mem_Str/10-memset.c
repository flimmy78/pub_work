/*******************************************************************
 *   > File Name: 10-memset.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:05:47 2017
 ******************************************************************/
#if (0)
void *memset(void *s, int c, size_t n);
//@FUNC:将参数 s 所指的内存区域前 n 个字节以参数 c 填入，
//然后返回指向 s 的指针。在编写程序时，若需要将某一数组作初始
//化，memset（）会相当方便
//参数 c 虽声明为 int，但必须是 unsigned char ，所以范围在 0 到 255
//之间。
//@RETURN:返回指向s的指针；
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s[30];
    memset(s, 'A', sizeof(s));
    s[30] = 0;
    printf("%s\n", s);

    return 0;
}
