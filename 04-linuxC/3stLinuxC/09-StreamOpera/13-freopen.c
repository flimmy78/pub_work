/*******************************************************************
 *   > File Name: 13-freopen.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 15:17:13 2017
 ******************************************************************/
#if (0)
FILE *freopen(const char *path, const char *mode, FILE *stream);    //打开文件
//参数 path 字符串包含欲打开的文件路径及文件名，参数 mode 请参
//考 fopen（）说明。参数 stream 为已打开的文件指针。freopen（）
//会将原 stream 所打开的文件流关闭，然后打开参数 path 的文件。
//文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开
//失败则返回 NULL，并把错误代码存在 errno 中。
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;

    fp = fopen("/etc/passwd", "r");
    printf("%p\n", fp);
    fp = freopen("/etc/group", "r", fp);
    printf("%p\n", fp);
    fclose(fp);

    return 0;
}
