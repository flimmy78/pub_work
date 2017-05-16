/*******************************************************************
 *   > File Name: 50-gettimeofday.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 16 May 2017 09:56:15 AM CST
 ******************************************************************/
#if (0)
#include <sys/time.h>
int gettimeofday(struct timeval *tv, struct timezone *tz);

struct timeval{
    time_t tv_sec;
    suseconds_t tv_usec;
};

struct timezone{
    int tz_minuteswest;
    int tz_dsttime;
};

#endif

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
    struct timeval now;

    gettimeofday(&now, NULL);
    printf("%ld %ld\n",now.tv_sec, now.tv_usec);

    return 0;
}
