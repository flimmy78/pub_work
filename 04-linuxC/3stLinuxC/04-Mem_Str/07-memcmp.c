/*******************************************************************
 *   > File Name: 07-memcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 12:34:22 2017
 ******************************************************************/
#if (0)
int memcmp(const void *s1, const void *s2, size_t n);
//@FUNC:比较内存区域
//用来比较 s1 和 s2 所指的内存区间前 n 个字符。字符
//串大小的比较是以 ASCII 码表上的顺序来决定，次顺序亦为字符的
//值。memcmp（）首先将 s1 第一个字符值减去 s2 第一个字符的值，
//若差为 0 则再继续比较下个字符，若差值不为 0 则将差值返回。例
//如，字符串“Ac”和“ba”比较则会返回字符‘A’（65）和‘b’
//（98）的差值（－33）。
//@return:若参数 s1 和 s2 所指的内存内容都完全相同则返回 0 值。s1 若大于
//s2 则返回大于 0 的值。s1 若小于 s2 则返回小于 0 的值。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{   
    char *a = "aBcDeF";
    char *b = "AbCdEf";
    char *c = "abcdeF";
    char *d = "aBcDeF";

    printf("memcmp(a, b) :%d\n", memcmp((void*)a, (void*)b, 6));
    printf("memcmp(a, c) :%d\n", memcmp((void*)a, (void*)c, 6));
    printf("memcmp(a, d) :%d\n", memcmp((void*)a, (void*)d, 6));

    return 0;
}
