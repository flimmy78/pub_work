/*******************************************************************
 *   > File Name: 28-strtok.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 17:55:54 2017
 ******************************************************************/
#if (0)
char *strtok(char *str, const char *delim);
//将字符串分割成一个个片段。参数 s 指向欲分割的字
//符串，参数 delim 则为分割字符串，当 strtok（）在参数 s 的字符串
//中发现到参数 delim 的分割字符时则会将该字符改为\0 字符。在第
//一次调用时，strtok（）必需给予参数 s 字符串，往后的调用则将参
//数 s 设置成 NULL。每次调用成功则返回下一个分割后的字符串指
//针。
//返回下一个分割后的字符串指针，如果已无从分割则返回 NULL。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s[] = "ab-cd:ef;gh:i-jkl;mnop;qrs-tu:vwx-y;z";
    char *delim = "-:";
    char *p;

    printf("%s\n\n", s);
    printf("%s", strtok(s, delim));
    while((p = strtok(NULL, delim))){
        printf("%s", p);
    }
    printf("\n");

    return 0;
}
