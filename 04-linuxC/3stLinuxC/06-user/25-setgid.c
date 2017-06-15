/*******************************************************************
 *   > File Name: 25-setgid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 17:41:18 2017
 ******************************************************************/
#if (0)
int setgid(gid_t gid);  //设置真实的组识别码
//将目前进程的真实组识别码（real gid）设成参数 gid
//值。如果是以超级用户身份执行此调用，则 real、effective 与 saved
//gid 都会设成参数 gid。
//设置成功则返回 0，失败则返回-1，错误代码存于 errno 中。
//EPERM 并非以超级用户身份调用，而且参数 gid 并非进程的
//effective gid 或 saved gid 值之一。
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
