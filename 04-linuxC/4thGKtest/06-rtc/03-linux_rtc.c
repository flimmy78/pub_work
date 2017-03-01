/*******************************************************************
 *   > File Name: 03-linux_rtc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 01 Mar 2017 10:16:26 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <linux/rtc.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>


#if (1)
#define DEVPATH "/dev/rtc"
#else
//#define DEVPATH "/dev/rtc0"
#define DEVPATH "/dev/rtc8563_io_dev"
#endif


int main(int argc, char* argv[])
{
    int fd, retval;
    struct rtc_time rtc_tm;
    time_t timep;
    struct tm *p;

    fd = open(DEVPATH,O_RDONLY);
    if(fd == -1){
        fprintf(stderr, "open %s err : %s\n",DEVPATH,(char*)strerror(errno));exit(errno);
    }

    /*Read the RTC time/data*/
    retval = ioctl(fd, RTC_RD_TIME, &rtc_tm);
    if(retval == -1){
        perror("ioctl");exit(errno);
    }
    close(fd);

    fprintf(stdout, "RTC data/time : %d/%d/%d  %02d:%02d:%02d\n",\
        rtc_tm.tm_mday,\
        rtc_tm.tm_mon + 1,\
        rtc_tm.tm_year + 1900,\
        rtc_tm.tm_hour + 8,\
        rtc_tm.tm_min,\
        rtc_tm.tm_sec);

    time(&timep);/*get current system time*/
    p = gmtime(&timep);
    
    /*获取系统（RTC）时间*/
    fprintf(stdout, "OS data/time(UTC) : %d/%d/%d  %02d:%02d:%02d\n",\
        p->tm_mday,\
        p->tm_mon + 1,\
        p->tm_year + 1900,\
        p->tm_hour + 8,\
        p->tm_min,\
        p->tm_sec);

    /*获取本地时间*/
    p = localtime(&timep);
    fprintf(stdout, "OS data/time(local) : %d/%d/%d  %02d:%02d:%02d\n",\
        p->tm_mday,\
        p->tm_mon + 1,\
        p->tm_year + 1900,\
        p->tm_hour,\
        p->tm_min,\
        p->tm_sec);

    return 0;
}
