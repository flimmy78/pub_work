/*******************************************************************
 *   > File Name: 14-strchr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:38:52 2017
 ******************************************************************/
#if (0)
char *strchr(const char *s, int c);
//@FUNC:找出参数 s 字符串中第一个出现的参数 c 地址，然后
//将该字符出现的地址返回。
//@Return:如果找到指定的字符则返回该字符所在地址，否则返回 0
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *s = "01234567980124567901234657980";
    char *p;

    p = strchr(s, '5');
    printf("%s\n", p);

    return 0;
}
