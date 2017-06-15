/*******************************************************************
 *   > File Name: 27-setgroups.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 17:48:55 2017
 ******************************************************************/
#if (0)
int getgroups(int size, gid_t list[]);a //设置组代码
//setgroups（）用来将 list 数组中所标明的组加入到目前进程的组设
//置中。参数 size 为 list〔〕的 gid_t 数目，最大值为 NGROUP(32)。
//设置成功则返回 0，如有错误则返回-1。
//EFAULT 参数 list 数组地址不合法。
//EPERM 权限不足，必须是 root 权限
//EINVAL 参数 size 值大于 NGROUP(32)
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

int main(int argc, char* argv[])
{
    return 0;
}
