/*******************************************************************
 *   > File Name: 11-rindex.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:10:13 2017
 ******************************************************************/
#if (0)
char *rindex(const char *s, int c);
//@FUNC:找出参数 s 字符串中最后一个出现的参数 c 地址，
//然后将该字符出现的地址返回。字符串结束字符（NULL）也视为
//字符串一部分
//@RETURN:如果找到指定的字符则返回该字符所在的地址，否则返回 0。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s[] = "012345678901245678901234567980";
    char c = '5';
    char *p;
    printf("%s\n", s);

    p = rindex(s,c);
    printf("%s\n", p);

    return 0;
}
