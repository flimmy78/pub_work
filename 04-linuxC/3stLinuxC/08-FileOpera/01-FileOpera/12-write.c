/*******************************************************************
 *   > File Name: 12-write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 11:42:52 2017
 ******************************************************************/
#if (0)
ssize_t write(int fildes, const void *buf, size_t nbyte);//将数据写入已打开的文件内
//把参数 buf 所指的内存写入 count 个字节到参数 fd 所指
//的文件内。当然，文件读写位置也会随之移动。
//如果顺利 write（）会返回实际写入的字节数。当有错误发生时则返
//回-1，错误代码存入 errno 中
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
