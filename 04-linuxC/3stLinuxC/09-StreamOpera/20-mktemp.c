/*******************************************************************
 *   > File Name: 20-mktemp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 16:39:42 2017
 ******************************************************************/
#if (0)
char *mktemp(char *template);   //产生唯一的临时文件名
//用来产生唯一的临时文件名。参数 template 所指的文件
//名称字符串中最后六个字符必须是 XXXXXX。产生后的文件名会
//借字符串指针返回。
//文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开
//失败则返回 NULL，并把错误代码存在 errno 中。
//参数 template 所指的文件名称字符串必须声明为数组，如 char
//template[ ]=”template-XXXXXX” ； 不 可 用 char *
//template=”template-XXXXXX”；
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char template[] = "template-XXXXXX";
    mktemp(template);
    printf("template = %s\n", template);

    return 0;
}
