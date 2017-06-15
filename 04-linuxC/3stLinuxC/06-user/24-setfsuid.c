/*******************************************************************
 *   > File Name: 24-setfsuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 17:38:06 2017
 ******************************************************************/
#if (0)
int setfsuid(uid_t fsuid);  //设置文件系统的用户识别码
//用来重新设置目前进程的文件系统的用户识别码。一般
//情况下，文件系统的用户识别码（fsuid）与有效的用户识别码（euid）
//是相同的。如果是超级用户调用此函数，参数 fsuid 可以为任何值，
//否则参数 fsuid 必须为 real/effective/saved 的用户识别码之一。
//执行成功则返回 0，失败则返回-1，错误代码存于 errno
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
