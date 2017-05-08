/*******************************************************************
 *   > File Name: 48-time_string.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 10:21:24 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if(argc != 2){
        printf("Usage :%s  <time_string>\n", argv[0]);exit(1);
    }
    printf("%s\n", argv[1]);
    struct tm time_tm;
    
    sscanf(argv[1], "%d-%d-%d_%d:%d:%d",\
            &time_tm.tm_year,\
            &time_tm.tm_mon,\
            &time_tm.tm_mday,\
            &time_tm.tm_hour,\
            &time_tm.tm_min,\
            &time_tm.tm_sec);
    time_tm.tm_year -= 1900;
    time_tm.tm_mon -= 1;

    time_t set_sec, sys_sec;
    set_sec = mktime(&time_tm);
    sys_sec = time(NULL);
    printf("set_sec = %ld\tsys_sec = %ld\n", set_sec, sys_sec);
   //printf("%s\n", asctime(&time_tm));

    return 0;
}
