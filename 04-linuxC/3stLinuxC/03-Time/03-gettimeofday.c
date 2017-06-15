/*******************************************************************
 *   > File Name: 03-gettimeofday.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 16:27:18 2017
 ******************************************************************/
#if (0)
int gettimeofday(struct timeval *tv, struct timezone *tz);
//把目前的时间有 tv 所指的结构返回，当地时区
//的信息则放到 tz 所指的结构中
struct timeval{
    time_t tv_sec;          /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};
struct timezone{
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};
#endif

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct  timeval tv;
    struct timezone tz;

    gettimeofday(&tv, &tz);
    printf("tv_sec : %ld\n", tv.tv_sec);
    printf("tv_usec : %ld\n", tv.tv_usec);
    printf("tz_minutewest : %d\n", tz.tz_minuteswest);
    printf("tz_dsttime : %d\n", tz.tz_dsttime);

    return 0;
}
