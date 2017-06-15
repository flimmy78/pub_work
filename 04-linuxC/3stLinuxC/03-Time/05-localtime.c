/*******************************************************************
 *   > File Name: 05-localtime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 09:20:24 2017
 ******************************************************************/
#if (0)
struct tm *localtime(const time_t *timep);//取得当地目前时间和日期
#endif

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;

    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    printf("%d-%d-%d-", 1900 + p -> tm_year, (1 + p -> tm_mon), p -> tm_mday);
    printf("%s %d:%d:%d\n", wday[p -> tm_wday], p -> tm_hour, p -> tm_min, p -> tm_sec);

    return 0;
}
