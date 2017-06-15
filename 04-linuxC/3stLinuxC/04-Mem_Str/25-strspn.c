/*******************************************************************
 *   > File Name: 25-strspn.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 17:32:54 2017
 ******************************************************************/
#if (0)
size_t strspn(const char *s, const char *accept);
//从参数 s 字符串的开头计算连续的字符，而这些字符都完
//全是 accept 所指字符串中的字符。简单的说，若 strspn（）返回的数值为 n，
//则代表字符串 s 开头连续有 n 个字符都是属于字符串accept 内的字符。
//返回字符串 s 开头连续包含字符串 accept 内的字符数目。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *str = "LinuxABCDEF was first developed for 386/486-based PCs.";
    char *t1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    printf("%s\n%s\n", str, t1);
    printf("%ld\n",strspn(str, t1));

    return 0;
}
