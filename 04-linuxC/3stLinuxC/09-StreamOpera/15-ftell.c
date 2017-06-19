/*******************************************************************
 *   > File Name: 15-ftell.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 15:58:50 2017
 ******************************************************************/
#if (0)
long ftell(FILE *stream);   //确定当前文件的位置
//来取得文件流目前的读写位置。参数 stream 为已打开的文件指针。
//当调用成功时则返回目前的读写位置，若有错误则返回-1，errno 会
//存放错误代码。
//EBADF 参数 stream 无效或可移动读写位置的文件流
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
