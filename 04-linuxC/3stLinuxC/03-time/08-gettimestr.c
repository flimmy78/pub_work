#include <stdio.h>
#include <time.h>

#if 0
int gettimestr(void)
{
    //char tm_str[20];
    time_t tm;
    struct tm* ptm;

    time(&tm);
    ptm = gmtime(&tm);
    fprintf(stdout,"%04d-%02d-%02d_%02d:%02d:%02d\n",
            ptm->tm_year +1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour,
            ptm->tm_min,
            ptm->tm_sec);

    return 0;
}
#else
int gettimestr(char* tm_str, int len)
{
    time_t tm;
    struct tm* ptm;

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
    printf("[%s] %s\n",__func__,tm_str);

    return 0;
}
#endif

int main(void)
{
    char string[20];
    gettimestr(string,20);
    printf("[%s] %s\n",__func__,string);

    //return (gettimestr());
    return 0;
}
