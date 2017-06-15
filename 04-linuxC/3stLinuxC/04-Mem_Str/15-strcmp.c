/*******************************************************************
 *   > File Name: 15-strcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:42:43 2017
 ******************************************************************/
#if (0)
int strcmp(const char *s1, const char *s2);
//@FUNC:用来比较参数 s1 和 s2 字符串。字符串大小的比较是以
//ASCII 码表上的顺序来决定，此顺序亦为字符的值。strcmp（）首
//先将 s1 第一个字符值减去 s2 第一个字符值，若差值为 0 则再继续
//比较下个字符，若差值不为 0 则将差值返回。例如字符串“Ac”和
//“ba”比较则会返回字符“A”（65）和‘b’（98）的差值（－33）。
//@Return:若参数 s1 和 s2 字符串相同则返回 0。s1 若大于 s2 则返回大于 0 的
//值。s1 若小于 s2 则返回小于 0 的值。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *a = "aBcDeF";
    char *b = "AbCdEf";
    char *c = "abcdeF";
    char *d = "aBcDeF";

    printf("strcmp(a, b) :%d\n", strcmp(a, b));
    printf("strcmp(a, c) :%d\n", strcmp(a, c));
    printf("strcmp(a, d) :%d\n", strcmp(a, d));

    return 0;
}
