/*******************************************************************
 *   > File Name: 20-initgroups.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 13:05:51 2017
 ******************************************************************/
#if (0)
int initgroups(const char *user, gid_t group);//初始化组清单
//从组文件（/etc/group）中读取一项组数据，若该
//组数据的成员中有参数 user 时，便将参数 group 组识别码加入到此
//数据中。
//执行成功则返回 0，失败则返回-1，错误码存于 errno。
#endif

#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

int main(int argc, char* argv[])
{
    return 0;
}
