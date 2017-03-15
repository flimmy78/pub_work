/*******************************************************************
 *   > File Name: 13-getpwuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 02:54:54 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct passwd *pw;

    pw = getpwuid(getuid());
    printf("pw_name :%s\npw_uid :%d\npw_gid :%d\npw_dir :%s\npw_gecos :%s\npw_shell :%s\n",
            pw->pw_name,
            pw->pw_uid,
            pw->pw_gid,
            pw->pw_dir,
            pw->pw_gecos,
            pw->pw_shell);

    return 0;
}
