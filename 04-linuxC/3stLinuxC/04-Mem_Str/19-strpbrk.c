/*******************************************************************
 *   > File Name: 19-strpbrk.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 06 Apr 2017 11:24:18 AM CST
 ******************************************************************/
#if (0)
#include <string.h>
char *strpbrk(const char *s, const char *accept);
//@FUNC:找出参数S字符串中最先出现存在参数accept字符串中的任意字符；
#endif

#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char *s = "012345678901234567890124567890";
    char *p;
    p = strpbrk(s,"a1839");
    printf("%s\n",p);
    p = strpbrk(s, "4389");
    printf("%s\n",p);

    return 0;
}
