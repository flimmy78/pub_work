/*******************************************************************
 *   > File Name: 23-strpbrk.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 17:16:27 2017
 ******************************************************************/
#if (0)
char *strpbrk(const char *s, const char *accept);
//找出参数 s 字符串中最先出现存在参数 accept 字符
//串中的任意字符。
//如果找到指定的字符则返回该字符所在地址，否则返回 0。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *s = "0123456798012345679801234657890";
    char *p;
    printf("%s\n", s);

    p = strpbrk(s, "89");
    printf("%s\n", p);
    p = strpbrk(s, "4398");
    printf("%s\n", p);

    return 0;
}
