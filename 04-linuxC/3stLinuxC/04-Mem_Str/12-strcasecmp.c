/*******************************************************************
 *   > File Name: 12-strcasecmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:16:17 2017
 ******************************************************************/
#if (0)
int strcasecmp(const char *s1, const char *s2);
//@FUNC:比较参数 s1 和 s2 字符串，比较时会自动忽略大小写的差异。
//@Return:若参数 s1 和 s2 字符串相同则返回 0。s1 长度大于 s2 长度则返回大
//于 0 的值，s1 长度若小于 s2 长度则返回小于 0 的值。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *a = "aBcDeF";
    char *b = "AbCdEf";

    int ret;
    if(!(ret = strcasecmp(a, b))){
        printf("%s = %s\n",a, b);
    }
    printf("ret = %d\n", ret);

    return 0;
}
