/*******************************************************************
 *   > File Name: 03-fdopen.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 12:04:31 2017
 ******************************************************************/
#if (0)
FILE *fdopen(int fd, const char *mode); //将文件描述词转成文件指针
//将参数 fildes 的文件描述词，转换为对应的文件指针
//后返回。参数 mode 字符串则代表着文件指针的流形态，此形态必
//须和原先文件描述词读写模式相同。关于 mode 字符串格式请参考
//fopen（）。
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp = fdopen(0, "w+");

    fprintf(fp,"%s\n", "Hello");
    fclose(fp);

    return 0;
}
