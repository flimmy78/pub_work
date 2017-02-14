/*******************************************************************
 *   > File Name: 02-perror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 06:27:20 PM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
#include <stdio.h>
void perror(const char *s);/*打印出错误原因信息字符串*/
//perror（）用来将上一个函数发生错误的原因输出到标准错误
//（stderr）。参数s 所指的字符串会先打印出，后面再加上错误原因
//字符串。此错误原因依照全局变量errno 的值来决定要输出的字符
//串。
#include <error.h>
const char *sys_errlist[];
int sys_nerr;
int errno;

#endif

int main(int argc, char* argv[])
{
    FILE *fp;
    fp = fopen("/tmp/noexist","r+");
    if(fp == NULL)
        perror("fopen");

    return 0;
}
