/*******************************************************************
 *   > File Name: 15-getpwuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:26:31 2017
 ******************************************************************/
#if (0)
struct passwd *getpwuid(uid_t uid);//从密码文件中取得指定uid的数据
//来逐一搜索参数 uid 指定的用户识别码，找到时便
//将该用户的数据以 passwd 结构返回。passwd 结构请参考 getpwent
//返回 passwd 结构数据，如果返回 NULL 则表示已无数据，或者有
//错误发生
#endif

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[])
{
    struct passwd *user;
    user = getpwuid(6);

    printf("name :%s\n", user -> pw_name);
    printf("uid :%d\n", user -> pw_uid);
    printf("home :%s\n", user -> pw_dir);

    return 0;
}
