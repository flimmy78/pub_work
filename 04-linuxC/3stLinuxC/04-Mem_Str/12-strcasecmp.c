/*******************************************************************
 *   > File Name: 12-strcasecmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 01:44:49 PM CST
 ******************************************************************/
#if (0)
int strcasecmp(const char *s1, const char *s2);
//@function:比较参数 s1 和 s2 字符串，比较时会自动忽略大
//小写的差异
//@return:若参数 s1 和 s2 字符串相同则返回 0。s1 长度大于 s2 长度则返回大
//于 0 的值，s1 长度若小于 s2 长度则返回小于 0 的值。
int strncasecmp(const char *s1, const char *s2, size_t n);
#endif

#include <stdio.h>
/*INC for strcasecmp*/
#include <strings.h>

int main(int argc, char* argv[])
{
    char *Base = "abcde";
    char *str1 = "ABCde";
    char *str2 = "abc";
    char *str3 = "abcDEFG";

    int retval;

    retval = strcasecmp(Base, str1);
    printf("strcasecmp :%s&%s\t retval = %d\n",Base, str1,retval);
    retval = strcasecmp(Base, str2);
    printf("strcasecmp :%s&%s\t retval = %d\n",Base, str2,retval);
    retval = strcasecmp(Base, str3);
    printf("strcasecmp :%s&%s\t retval = %d\n",Base, str3,retval);

    return 0;
}
