/*******************************************************************
 *   > File Name: 06-settimeofday.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 04:04:07 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/time.h>

#if (0)
 int settimeofday(const struct timeval *tv, const struct timezone *tz);
 //设置目前时间
 //settimeofday（）会把目前时间设成由 tv 所指的结构信息，当地时
 //区信息则设成 tz 所指的结构。详细的说明请参考 gettimeofday（）。
 //注意，只有 root 权限才能使用此函数修改时间
 //struct timeval {
 //               time_t      tv_sec;     /* seconds */
 //               suseconds_t tv_usec;    /* microseconds */
 //               };
 // struct timezone {
 //                int tz_minuteswest;     /* minutes west of Greenwich */
 //                int tz_dsttime;         /* type of DST correction */
 //                 };
 //

#endif

int main(int argc, char* argv[])
{
    struct timeval tv;
    struct timezone tz;

    int ret;

    ret = gettimeofday(&tv, &tz);
    if(ret != 0)
    {
        perror("gettimeofday err");
        return (-1);
    }

    printf("秒数：%ld\t微秒：%ld\n",tv.tv_sec, tv.tv_usec);
    printf("tz_minuteswest : %d\ttz_dsttime ：%d\n",tz.tz_minuteswest, tz.tz_dsttime);

    ret = settimeofday(&tv, &tz);
    if(ret != 0)
    {
        perror("settimeofday err");
        return (-1);
    }
    else
    {
        printf("settimeofday ok\n");
    }


    return 0;
}
