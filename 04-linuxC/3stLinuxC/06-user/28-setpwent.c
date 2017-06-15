/*******************************************************************
 *   > File Name: 28-setpwent.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 17:54:21 2017
 ******************************************************************/
#if (0)
void setpwent(void);    //从头读取密码文件中的账号数据
//用来将getpwent()的读写地址指向密码文件开头
#endif

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[])
{   
    struct passwd *user;
    int i;

    for(i = 0; i < 4; i++){
        user = getpwent();
        printf("%s : %d :%d :%s :%s :%s\n",
                user -> pw_name,
                user -> pw_uid,
                user -> pw_gid,
                user -> pw_gecos,
                user -> pw_dir,
                user -> pw_shell);
    }
        setpwent();
        user = getpwent();

        printf("%s :%d :%d :%s :%s :%s\n",
                user -> pw_name,
                user -> pw_uid,
                user -> pw_gid,
                user -> pw_gecos,
                user -> pw_dir,
                user -> pw_shell);
        endpwent();

    return 0;
}
