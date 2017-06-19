/*******************************************************************
 *   > File Name: 14-fseek.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 15:23:49 2017
 ******************************************************************/
#if (0)
int fseek(FILE *stream, long offset, int whence);   //移动文件流的读写位置
//用来移动文件流的读写位置。参数 stream 为已打开的文件
//指针，参数 offset 为根据参数 whence 来移动读写位置的位移数。参
//数 whence 为下列其中一种：SEEK_SET 从距文件开头 offset 位移量
//为新的读写位置。SEEK_CUR 以目前的读写位置往后增加 offset 个
//位移量。SEEK_END 将读写位置指向文件尾后再增加 offset 个位移量。
//当 whence 值为 SEEK_CUR 或 SEEK_END 时，参数 offset 允许负
//值的出现。下列是较特别的使用方式：
(1) 欲 将 读 写 位 置 移 动 到 文 件 开 头 时 ： fseek(FILE *stream,0,SEEK_SET);
(2) 欲 将 读 写 位 置 移 动 到 文 件 尾 时 ： fseek(FILE *stream,0,SEEK_END);
//当调用成功时则返回 0，若有错误则返回-1，errno 会存放错误代码。
//fseek（）不像 lseek（）会返回读写位置，因此必须使用 ftell（）来
//取得目前读写的位置。
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *stream;
    long offset;
    fpos_t pos;

    stream = fopen("/etc/passwd", "r");     //以可读方式打开文件
    fseek(stream, 5, SEEK_SET);             
    printf("offset = %d\n", ftell(stream));
    rewind(stream);
    fgetpos(stream, &pos);
    pos = 10;
    fsetpos(stream, &pos);
    printf("offset = %d\n", ftell(stream));
    fclose(stream);

    return 0;
}
