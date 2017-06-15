/*******************************************************************
 *   > File Name: 30-setreuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 18:05:50 2017
 ******************************************************************/
#if (0)
int setreuid(uid_t ruid, uid_t euid);   //设置真实及有效的用户识别码
//用来将参数 ruid 设为目前进程的真实用户识别码，将参
//数 euid 设置为目前进程的有效用户识别码。如果参数 ruid 或 euid
//值为-1，则对应的识别码不会改变。
//执行成功则返回 0，失败则返回-1，错误代码存于 errno。
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
