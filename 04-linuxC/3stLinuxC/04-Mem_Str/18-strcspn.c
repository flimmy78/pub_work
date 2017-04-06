/******************************************************************
 *   > File Name: 18-strcspn.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 08 Mar 2017 01:49:05 PM CST
 ******************************************************************/
#if (0)
size_t strspn(const char *s, const char *accept);

size_t strcspn(const char *s, const char *reject);
//@FUNC:返回字符串中连续不含指定字符串内容的字符数
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *str = "Linux was first developed for 386/486-based PCs.";
    char *t1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKMNOPQRSTUVWXYZ";
    printf("%s\n%s\n", str, t1);
    printf("%d\n",strcspn(str, t1));

    return 0;
}

