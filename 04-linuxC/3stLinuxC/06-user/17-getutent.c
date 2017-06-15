/*******************************************************************
 *   > File Name: 17-getutent.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:35:20 2017
 ******************************************************************/
#if (0)
struct utmp *getutent(void);//从utmp文件中取得账号登录数据库
//getutent（）用来从 utmp 文件（/var/run/utmp）中读取一项登录数据，
//该数据以 utmp 结构返回。第一次调用时会取得第一位用户数据，
//之后每调用一次就会返回下一项数据，直到已无任何数据时返回
//NULL。
//返回 utmp 结构数据，如果返回 NULL 则表示已无数据，或有错误
//发生。
//getutent（）在第一次调用时会打开 utmp 文件，读取数据完毕后可
//使用 endutent（）来关闭该 utmp 文件.
#endif

#include <stdio.h>
#include <utmp.h>

int main(int argc, char* argv[])
{
    struct utmp *u;
    
    while(( u = getutent() )){
        if(u -> ut_type == USER_PROCESS)
            printf("%d %s %s %s\n", u -> ut_type, u -> ut_user, u -> ut_line, u -> ut_host);
    }

    endutent();

    return 0;
}
