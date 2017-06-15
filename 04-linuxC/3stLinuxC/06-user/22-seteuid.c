/*******************************************************************
 *   > File Name: 22-seteuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 17:27:30 2017
 ******************************************************************/
#if (0)
int seteuid(uid_t euid);    //设置有效的用户识别码
//用来重新设置执行目前进程的有效用户识别码。在 Linux
//下，seteuid（euid）相当于 setreuid（-1,euid）。
//执行成功则返回 0，失败则返回-1，错误代码存于 errno
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
