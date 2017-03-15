/*******************************************************************
 *   > File Name: 07-gmtime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 09:21:46 AM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    struct tm *ptm;
    time_t the_time;

    time((time_t *)&the_time);
    ptm = gmtime(&the_time);

    printf("Raw_time is :%ld\n", the_time);
    printf("\tgmtime gives :\n");
    printf("date :%04d/%02d/%02d\n",
            ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday);
    printf("time :%2d:%2d:%2d\n",
            ptm->tm_hour + 8, ptm->tm_min, ptm->tm_sec);

    ptm = localtime(&the_time);
    printf("\n\tlocaltime gives :\n");
    printf("date :%04d/%02d/%02d\n",
            ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday);
    printf("time :%2d:%2d:%2d\n",
            ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    return 0;
}
