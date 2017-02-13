#include <stdio.h>
#include <time.h>

#define T_STR_FORMAT "xxxx-xx-xx_xx:xx:xx"

char* gettimestr(char* tm_str, int len)
{
    time_t tm;
    struct tm* ptm;

    if(len < 20)
    {
        printf("Buf len is less than %d\n",sizeof T_STR_FORMAT);
        return NULL;
    }

    time(&tm);
    ptm = gmtime(&tm);
    snprintf(tm_str,len,"%04d-%02d-%02d_%02d:%02d:%02d",
            ptm->tm_year + 1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour + 8,
            ptm->tm_min,
            ptm->tm_sec);
    //printf("[%s] %s\n",__func__,tm_str);

    return tm_str;
}

int main(void)
{
    char string[20];

    printf("sizeof T_STR_FORMAT :%d\n",sizeof T_STR_FORMAT);

    printf("gettimestr: %s\n",gettimestr(string,20));
    printf("[%s] %s\n",__func__,string);

    return 0;
}
