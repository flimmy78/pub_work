/*******************************************************************
 *   > File Name: 06-mktime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 09:35:35 2017
 ******************************************************************/
#if (0)
time_t mktime(struct tm *tm);//将时间结构数据转化成经过的秒数
#endif

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t timep;
    struct tm *p;

    time(&timep);
    printf("time() :%ld\n", timep);
    p = localtime(&timep);
    timep = mktime(p);
    printf("time() -> localtime() -> mktime() :%ld\n", timep);
    

    return 0;
}
