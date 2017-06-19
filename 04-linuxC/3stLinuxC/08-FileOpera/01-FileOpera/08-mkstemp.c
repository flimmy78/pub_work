/*******************************************************************
 *   > File Name: 08-mkstemp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 10:15:22 2017
 ******************************************************************/
#if (0)
int mkstemp(char *template);    //建立唯一的临时文件
//用来建立唯一的临时文件。参数 template 所指的文件
//名称字符串中最后六个字符必须是 XXXXXX。mkstemp（）会以可
//读写模式和 0600 权限来打开该文件，如果该文件不存在则会建立
//该文件。打开该文件后其文件描述词会返回。
//文件顺利打开后返回可读写的文件描述词。若果文件打开失败则返
//回 NULL，并把错误代码存在 errno 中。
//参数 template 所指的文件名称字符串必须声明为数组，如：
//char template[] =”template-XXXXXX”;
//千万不可以使用下列的表达方式
//char *template = “template-XXXXXX”;
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd;

    char template[] = "template-XXXXXX";
    fd = mkstemp(template);
    printf("template = %d\n", fd);
    close(fd);

    return 0;
}
