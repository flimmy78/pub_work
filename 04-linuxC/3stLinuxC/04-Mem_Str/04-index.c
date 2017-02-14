/*******************************************************************
 *   > File Name: 04-index.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 02:38:42 PM CST
 ******************************************************************/

#include <stdio.h>
#include <strings.h>

#if (0)
char *index(const char *s, int c);/*查找字符串第一个出现的指定字符*/
char *rindex(const char *s, int c);
//@return :成功返回匹配字符串的指针；未发现，返回NULL
#endif

int main(int argc, char* argv[])
{
    char *STR = "ABCDE6789012345";
    char *p;
    printf("STR :%s\t STR--%p\n",STR,STR);

    p = index(STR, 'E');
    printf("index p :%s\t p----%p\n",p,p);

    return 0;
}
