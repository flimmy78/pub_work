/*******************************************************************
 *   > File Name: 06-fsync.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 10:08:18 2017
 ******************************************************************/
#if (0)
int fsync(int fd);  //将磁盘区数据写回到磁盘
//将参数 fd 所指的文件数据，由系统缓冲区写回磁盘，
//以确保数据同步。
//成功则返回 0，失败返回-1，errno 为错误代码
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
