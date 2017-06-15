/*******************************************************************
 *   > File Name: 14-getpwnam.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:18:52 2017
 ******************************************************************/
#if (0)
struct passwd *getpwnam(const char *name);//从密码文件中取得指定账号的数据
//用来逐一搜索参数 name 指定的账号名称，找到时便
//将该用户的数据以 passwd 结构返回。passwd 结构请参考 getpwent
//（）。
//返回 passwd 结构数据，如果返回 NULL 则表示已无数据，或有错
//误发生
#endif

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[])
{
    struct passwd *user;
    
    user = getpwnam("root");
    printf("name :%s\n", user -> pw_name);
    printf("uid :%d\n", user -> pw_uid);
    printf("home :%s\n", user -> pw_dir);

    return 0;
}
