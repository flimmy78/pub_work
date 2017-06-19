/*******************************************************************
 *   > File Name: 23-setbuf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 16:54:50 2017
 ******************************************************************/
#if (0)
void setbuf(FILE *stream, char *buf);
//在打开文件流后，读取内容之前，调用 setbuf（）可以用来设置文
//件流的缓冲区。参数 stream 为指定的文件流，参数 buf 指向自定的
//缓冲区起始地址。如果参数 buf 为 NULL指针，则为无缓冲 IO。setbuf
//（）相当于调用：setvbuf(stream,buf,buf?IOFBF:_IONBF,BUFSIZ)
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
