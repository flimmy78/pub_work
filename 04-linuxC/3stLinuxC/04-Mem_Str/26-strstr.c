/*******************************************************************
 *   > File Name: 26-strstr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 17:49:31 2017
 ******************************************************************/
#if (0)
char *strstr(const char *haystack, const char *needle);
//从字符串 haystack 中搜寻字符串 needle，并将第一次出
//现的地址返回。
//返回指定字符串第一次出现的地址，否则返回 0。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *s = "012345678901245678901234567980";
    char *p;

    p = strstr(s, "901");
    printf("%s\n",p);

    return 0;
}
