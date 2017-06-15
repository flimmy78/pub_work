/*******************************************************************
 *   > File Name: 13-getpwent.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:05:13 2017
 ******************************************************************/
#if (0)
struct passwd *getpwent(void);//从密码文件中取得账号的数据
//从密码文件（/etc/passwd）中读取一项用户数据，
//该用户的数据以 passwd 结构返回。第一次调用时会取得第一位用
//户数据，之后每调用一次就会返回下一项数据，直到已无任何数据
//时返回 NULL
//返回 passwd 结构数据，如果返回 NULL 则表示已无数据，或有错
//误发生
#endif

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[])
{   
    struct passwd *user;

    while((user = getpwent()) != 0){
        printf("%s : %d : %d : %s : %s : %s\n", 
                user -> pw_name, 
                user -> pw_uid, 
                user -> pw_gid, 
                user -> pw_gecos,
                user -> pw_dir,
                user -> pw_shell);
    }

    return 0;
}
