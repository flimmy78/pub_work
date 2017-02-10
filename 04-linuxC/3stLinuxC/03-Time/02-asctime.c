/*******************************************************************
 *   > File Name: 02-asctime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 02:54:48 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

#if (0)
char *asctime(const struct tm *tm);/*将时间和日期以字符串格式表示*/
struct tm *gmtime(const time_t *timep);/*取得目前的时间和日期*/

struct tm {
    int tm_sec;         /* seconds */
    int tm_min;         /* minutes */
    int tm_hour;        /* hours */
    int tm_mday;        /* day of the month */
    int tm_mon;         /* month */
    int tm_year;        /* year */
    int tm_wday;        /* day of the week */
    int tm_yday;        /* day in the year */
    int tm_isdst;       /* daylight saving time */
};

#endif

int main(int argc, char* argv[])
{
    time_t tm;
    struct tm *stm;

    /*获取当前时间*/
    tm = time((time_t*)NULL);
    printf("tm = %ld\n",tm);
    /*将时间转化成结构体*/
    stm = gmtime(&tm);
    printf("秒数    ：%d\n",stm->tm_sec);
    printf("分钟    ：%d\n",stm->tm_min);
    printf("小时    ：%d\n",stm->tm_hour);
    printf("月之几天：%d\n",stm->tm_mday);
    printf("月      ：%d\n",stm->tm_mon);
    printf("年      ：%d\n",stm->tm_year+1900);
    printf("周之几天：%d\n",stm->tm_wday);
    printf("年之几天：%d\n",stm->tm_yday);
    printf("夏令    ：%d\n",stm->tm_isdst);
    /*将结构体转化成字符串*/
    printf("asctime(&stm) :%s",asctime(stm));/*自带换行*/

    return 0;
}
