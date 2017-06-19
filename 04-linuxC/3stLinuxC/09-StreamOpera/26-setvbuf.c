/*******************************************************************
 *   > File Name: 26-setvbuf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 17:05:58 2017
 ******************************************************************/
#if (0)
int setvbuf(FILE *stream, char *buf, int mode, size_t size);
//在打开文件流后，读取内容之前，调用 setvbuf（）可以用来设置文
//件流的缓冲区。参数 stream 为指定的文件流，参数 buf 指向自定的
//缓冲区起始地址，参数 size 为缓冲区大小，参数 mode 有下列几种：
//_IONBF    无缓冲IO
//_IOLBF    以换行为依据的无缓冲IO
//_IOFBF    完全无缓冲IO。如果参数BUF为NULL指针，则为无缓冲IO。
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
