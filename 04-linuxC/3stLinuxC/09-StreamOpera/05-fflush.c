/*******************************************************************
 *   > File Name: 05-fflush.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 13:16:06 2017
 ******************************************************************/
#if (0)
int fflush(FILE *stream);   //跟新缓冲区
//强迫将缓冲区内的数据写回参数 stream 指定的文件中。
//如果参数 stream 为 NULL，fflush（）会将所有打开的文件数据更新。
//成功返回 0，失败返回 EOF，错误代码存于 errno 中
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
