/*******************************************************************
 *   > File Name: 31-setuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 18:11:46 2017
 ******************************************************************/
#if (0)
int setuid(uid_t uid);  //设置真实的用户识别码
//setuid（）用来重新设置执行目前进程的用户识别码。不过，要让此
//函数有作用，其有效的用户识别码必须为 0（root）。在 Linux 下，
//当 root 使用 setuid（）来变换成其他用户识别码时，root 权限会被
//抛弃，完全转换成该用户身份，也就是说，该进程往后将不再具有
//可 setuid（）的权利，如果只是向暂时抛弃 root 权限，稍后想重新
//取回权限，则必须使用 seteuid（）。
//执行成功则返回 0，失败则返回-1，错误代码存于 errno。
//一般在编写具 setuid root 的程序时，为减少此类程序带来的系统安
//全风险，在使用完 root 权限后建议马上执行 setuid（getuid()）;来抛
//弃 root 权限。此外，进程 uid 和 euid 不一致时 Linux 系统将不会产
//生 core dump。
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
