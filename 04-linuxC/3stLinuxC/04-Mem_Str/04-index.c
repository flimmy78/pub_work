/*******************************************************************
 *   > File Name: 04-index.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 11:37:32 2017
 ******************************************************************/
#if (0)
char *index(const char *s, int c);
//@FUNC:查找字符串中第一个出现的指定字符
#endif

#include <stdio.h>
#include <strings.h>

int main(int argc, char* argv[])
{
    char *s = "012345678901234567890124567890";
    char *p;
    
    printf("s :%s\ns -->%p\n", s,s);
    p = index(s, '5');
    printf("p :%s\np -->%p\n", p,p);

    return 0;
}
