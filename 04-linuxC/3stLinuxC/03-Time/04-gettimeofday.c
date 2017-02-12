/*******************************************************************
 *   > File Name: 04-gettimeofday.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sun 12 Feb 2017 08:57:00 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/time.h>

#if (0)
int gettimeofday(struct timeval *tv, struct timezone *tz);/*取得目前时间*/

/*timeval结构体*/
struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};
/*timezone结构体*/
struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};
//@return:成功返回零，失败返回-1，错误代码存在errno

#endif

int main(int argc, char* argv[])
{   
    struct timeval tv;
    struct timezone tz;

    int ret = gettimeofday(&tv,&tz);
    if(ret == -1)
    {
        perror("gettimeofday err");
        return (-1);
    }

    printf("秒： %ld\n",tv.tv_sec);
    printf("微秒:%ld\n",tv.tv_usec);
    printf("和格林尼治时间差：%d\n",tz.tz_minuteswest);
    printf("日光节状态：%d\n",tz.tz_dsttime);

    return 0;
}
