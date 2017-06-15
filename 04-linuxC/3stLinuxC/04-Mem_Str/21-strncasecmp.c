/*******************************************************************
 *   > File Name: 21-strncasecmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 16:37:13 2017
 ******************************************************************/
#if (0)
int strncasecmp(const char *s1, const char *s2, size_t n);
//比较参数 s1 和 s2 字符串前 n 个字符，比较时
//会自动忽略大小写的差异。
//若参数 s1 和 s2 字符串相同则返回 0。s1 若大于 s2 则返回大于 0 的
//值，s1 若小于 s2 则返回小于 0 的值。
#endif

#include <stdio.h>
#include <strings.h>

int main(int argc, char* argv[])
{
    char *a = "ABcDeF";
    char *b = "ABCdEf";
    
    if(!strncasecmp(a,b,5)){
        printf("%s = %s\n",a,b);
    }

    return 0;
}
