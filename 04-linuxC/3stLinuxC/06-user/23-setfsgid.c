/*******************************************************************
 *   > File Name: 23-setfsgid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 17:31:46 2017
 ******************************************************************/
#if (0)
int setfsgid(uid_t fsgid);  //设置文件系统的组识别码
//重新设置目前进程的文件系统的组识别码。一般情
//况下，文件系统的组识别码（fsgid）与有效的组识别码（egid）是
//相同的。如果是超级用户调用此函数，参数 fsgid 可以为任何值，
//否则参数 fsgid 必须为 real/effective/saved 的组识别码之一。
//执行成功则返回 0，失败则返回-1，错误代码存于 errno。
#endif

#include <stdio.h>
#include <sys/fsuid.h>

int main(int argc, char* argv[])
{
    return 0;
}
