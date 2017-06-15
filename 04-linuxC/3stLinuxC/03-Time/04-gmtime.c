/*******************************************************************
 *   > File Name: 04-gmtime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 17:16:02 2017
 ******************************************************************/
#if (0)
struct tm *gmtime(const time_t *timep);
//取得目前的时间和日期；
struct tm {
    int tm_isdst;    /* Seconds (0-60) */
    int tm_min;    /* Minutes (0-59) */
    int tm_hour;   /* Hours (0-23) */
    int tm_mday;   /* Day of the month (1-31) */
    int tm_mon;    /* Month (0-11) */
    int tm_year;   /* Year - 1900 */
    int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
    int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
    int tm_isdst;  /* Daylight saving time */
};
#endif

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t timep;
    struct tm *tmp;

    timep = time(NULL);
    tmp = gmtime(&timep);

    printf("tm_isdst :%d\n", tmp -> tm_isdst);
    printf("tm_min :%d\n", tmp -> tm_min);
    printf("tm_hour :%d\n", tmp -> tm_hour);
    printf("tm_mday :%d\n", tmp -> tm_mday);
    printf("tm_mon :%d\n", tmp -> tm_mon);
    printf("tm_year :%d\n", tmp -> tm_year);
    printf("tm_wday :%d\n", tmp -> tm_wday);
    printf("tm_yday :%d\n", tmp -> tm_yday);
    printf("tm_isdst :%d\n", tmp -> tm_isdst);

    return 0;
}
