/*******************************************************************
 *   > File Name: 15-strcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 05:47:22 PM CST
 ******************************************************************/
#if (0)
/*比较字符串*/
int strcmp(const char *s1, const char *s2);
/**/
int strncmp(const char *s1, const char *s2, size_t n);
#endif

#include <stdio.h>
/*INC for strcmp*/
#include <string.h>

int main(int argc, char* argv[])
{
#if (0)
    char *a = "ABCDE";
    char *b = "ABCDE";
    char *c = "abcde";
    char *d = "@AAAA";
#else
    char *a = "aBcDeF";
    char *b = "AbCeEf";
    char *c = "aacdef";
    char *d = "aBcDeF";
#endif

    printf("a :%s\tb :%s\tc :%s\td :%s\n",a,b,c,d);
    /*s1中'a'大于s2中'A'，返回1*/
    printf("strcmp(a,b) :%d\n",strcmp(a,b));
    /*s1中'A'小于s2中'a'，返回-1*/
    printf("strcmp(a,c) :%d\n",strcmp(a,c));
    /*相同，返回0*/
    printf("strcmp(a,d) :%d\n",strcmp(a,d));

    return 0;
}
