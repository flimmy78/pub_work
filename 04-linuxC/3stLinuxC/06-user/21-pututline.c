/*******************************************************************
 *   > File Name: 21-pututline.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 13:08:48 2017
 ******************************************************************/
#if (0)
struct utmp *pututline(struct utmp *ut);//将utmp记录写入文件
//pututline（）用来将参数 ut 的 utmp 结构记录到 utmp 文件中。此函
//数会先用 getutid（）来取得正确的写入位置，如果没有找到相符的
//记录则会加入到 utmp 文件尾，utmp 结构请参考 getutent（）。
//无 需
//要有写入/var/run/utmp 的权限
#endif

#include <stdio.h>
#include <utmp.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct utmp ut;
    ut.ut_type = USER_PROCESS;
    ut.ut_pid = getpid();
    strcpy(ut.ut_user, "kids");
    strcpy(ut.ut_line, "pts/1");

    strcpy(ut.ut_host, "www.gnu.org");
    if(pututline(&ut) == NULL){
        perror("pututline");
    }

    return 0;
}
