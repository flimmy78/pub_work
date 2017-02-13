/*******************************************************************
 *   > File Name: 05-mktime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 03:44:54 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

#if (0)
time_t mktime(struct tm *tm);/*将时间结构数据转换成经过的秒数*/

#endif

int main(int argc, char* argv[])
{   

    time_t tm1,tm2;
    struct tm *ptm1;

    /*获取时间*/
    tm1 = time((time_t*)NULL);
    printf("tm1 = %ld\n",tm1);
    tm1 ++;/* 秒数加1*/

    /*将秒数转换成结构体数据*/
    ptm1 = gmtime(&tm1);

    /*将时间结构体数据转换成经过的秒数*/
    tm2 = mktime(ptm1);
    printf("tm2 = %ld\n",tm2);
    

    return 0;
}
