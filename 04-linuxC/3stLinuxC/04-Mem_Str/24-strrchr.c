/*******************************************************************
 *   > File Name: 24-strrchr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 17:26:32 2017
 ******************************************************************/
#if (0)
char *strrchr(const char *s, int c);
//找出参数 s 字符串中最后一个出现的参数 c 地址，
//然后将该字符出现的地址返回。
//如果找到指定的字符则返回该字符所在地址，否则返回 0。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{   
    char *s = "01245679012456798012456790";
    char *p;

    printf("%s\n", s);
    p = strrchr(s, '5');
    printf("%s\n", p);

    return 0;
}
