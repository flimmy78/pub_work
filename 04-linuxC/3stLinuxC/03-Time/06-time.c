/*******************************************************************
 *   > File Name: 06-time.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 09 Jan 2017 09:51:00 AM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

char *time_str(void)
{
    char tm_str[20];
    time_t tm;
    struct tm *ptm;

    time(&tm);
    ptm = gmtime(&tm);
    snprintf(tm_str,19,"%04d-%02d-%02d_%02d:%02d:%02d\n",
            ptm->tm_year +1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour,
            ptm->tm_min,
            ptm->tm_sec);
    tm_str[19] = '\0';
    printf("%s\n",tm_str);

    return tm_str;
}

int main(void)
{
#if (0)
    time_t tm;
    struct tm *ptm;
    time(&tm);
    ptm=gmtime(&tm);
    printf("%04d-%02d-%02d_%02d:%02d:%02d\n",
            ptm->tm_year + 1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour,
            ptm->tm_min,
            ptm->tm_sec);
#endif
    char tm[20];
    
    printf("In main : %s\n",time_str());

    return 0;
}
