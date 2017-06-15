/*******************************************************************
 *   > File Name: 18-getutid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:44:35 2017
 ******************************************************************/
#if (0)
struct utmp *getutid(struct utmp *ut);//从utmp文件中查找特定的记录
//etutid（）用来从目前 utmp 文件的读写位置逐一往后搜索参数 ut
//指定的记录，如果 ut->ut_type 为 RUN_LVL，BOOT_TIME，
//NEW_TIME，OLD_TIME 其中之一则查找与 ut->ut_type 相符的记
//录 ； 若 ut->ut_type 为 INIT_PROCESS ， LOGIN_PROCESS ，
//USER_PROCESS或 DEAD_PROCESS其中之一，则查找与 ut->ut_id
//相符的记录。找到相符的记录便将该数据以 utmp 结构返回。utmp
//结构请参考 getutent（）。
//返回 utmp 结构数据，如果返回 NULL 则表示已无数据，或有错误
//发生。
#endif

#include <stdio.h>
#include <utmp.h>

int main(int argc, char* argv[])
{
    struct utmp ut, *u;

    ut.ut_type = RUN_LVL;
    while((u = getutid(&ut))){
        printf("%d %s %s %s \n", u -> ut_type, u -> ut_user, u -> ut_line, u -> ut_host);
    }

    return 0;
}
