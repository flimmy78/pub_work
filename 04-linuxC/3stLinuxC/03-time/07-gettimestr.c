#include <stdio.h>
#include <time.h>

int gettimestr(char *tm_str, int len)
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
	
	return 0;
}