/*******************************************************************
 *   > File Name: 09-strftime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 11:15:07 AM CST
 ******************************************************************/
#if (0)
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
char *strptime(const char *s, const char *format, struct tm *tm);
#endif

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define _XOPEN_SOURCE

int main(int argc, char* argv[])
{
    struct tm *tm_ptr, timestruct;
    time_t the_time;
    char buf[256];
    char *result;

    (void)time((time_t*)&the_time);
    tm_ptr = localtime(&the_time);
    strftime(buf, 256, "%A %d %B, %I:%S %P", tm_ptr);
    
    printf("strftime give :%s\n", buf);

    strcpy(buf, "Thu 26 july 2007, 17:53 will do file");

    printf("calling strptime with :%s\n",buf);
    tm_ptr = &timestruct;

    result = (char *)strptime(buf, "%a %d %b %Y, %R", tm_ptr);
    printf("strptime consumed up to: %s\n", result);

    printf("strptime gives:\n");
    printf("date : %02d/%02d/%02d\n",
            tm_ptr->tm_year % 100, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
    printf("time :%02d:%02d\n",
            tm_ptr->tm_hour, tm_ptr->tm_min);

    return 0;
}
