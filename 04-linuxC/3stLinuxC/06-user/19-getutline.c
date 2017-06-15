/*******************************************************************
 *   > File Name: 19-getutline.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:51:40 2017
 ******************************************************************/
#if (0)
struct utmp *getutline(struct utmp *ut);//从utmp文件中查找特定的记录
//getutline（）用来从目前 utmp 文件的读写位置逐一往后搜索 ut_type
//为 USER_PROCESS 或 LOGIN_PROCESS 的记录，而且 ut_line 和
//ut->ut_line 相符。找到相符的记录便将该数据以 utmp 结构返回，
//utmp 结构请参考 getutent（）。
//返回 utmp 结构数据，如果返回 NULL 则表示已无数据，或有错误
//发生
#endif

#include <stdio.h>
#include <utmp.h>
#include <string.h>

int main(int argc, char* argv[])
{
    struct utmp ut, *u;

    strcpy(ut.ut_line, "pts/0");
    while((u = getutline(&ut))){
        printf("%d %s %s %s\n", u -> ut_type, u -> ut_user, u -> ut_line, u -> ut_host);
    }

    return 0;
}
