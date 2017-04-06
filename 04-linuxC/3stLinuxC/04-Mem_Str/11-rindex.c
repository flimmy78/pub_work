/*******************************************************************
 *   > File Name: 11-rindex.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 01:39:38 PM CST
 ******************************************************************/
#if (0)
char *index(const char *s, int c);
/*出参数 s 字符串中第一个出现的参数 c 地址，然后
 * 将该字符出现的地址返回。字符串结束字符（NULL）也视为字符
 * 串一部分*/
char *rindex(const char *s, int c);
#endif

#include <stdio.h>
/*INC for rindex*/
#include <strings.h>

int main(int argc, char* argv[])
{
    char *s = "012345678901234567890123456789";
    char *p;

    printf("%s\n",s);

    p = rindex(s, '5');
    printf("rindex \'5\' :%s\n",p);

    return 0;
}
