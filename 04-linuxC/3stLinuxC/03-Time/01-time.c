/*******************************************************************
 *   > File Name: 01-time.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 02:31:54 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

#if (0)
time_t time(time_t *t);/*取得目前的时间*/
//从1970年1月1日的UTC时间从0时0分0秒到现在经过的秒数
char *ctime(const time_t *timep);/*将时间和日期以字符串表示*/
#endif

int main(int argc, char* argv[])
{
    time_t tm1,tm2;

    /*获取当前时间*/
    tm1 = time(&tm2);
    printf("tm1 = %ld\ntm2 = %ld\n",tm1,tm2);
    /*将当前时间转化成字符串*/
    printf("ctime(&tm1) :%s",ctime(&tm1));/*自带换行*/
    printf("ctime(&tm2) :%s",ctime(&tm2));

    return 0;
}
