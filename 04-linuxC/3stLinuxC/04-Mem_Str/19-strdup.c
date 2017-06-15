/*******************************************************************
 *   > File Name: 19-strdup.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 16:26:38 2017
 ******************************************************************/
#if (0)
char *strdup(const char *s);
//用 maolloc（）配置与参数 s 字符串相同的空间大小，
//然后将参数 s 字符串的内容复制到该内存地址，然后把该地址返回。
//该地址最后可以利用 free（）来释放。
//返回一字符串指针，该指针指向复制后的新字符串地址。若返回
//NULL 表示内存不足
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[] = "strdup";
    char *b;

    b = strdup(a);
    printf("b[] = \"%s\"\n", b);

    return 0;
}
