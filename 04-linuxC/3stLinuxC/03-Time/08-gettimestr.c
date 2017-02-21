#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define T_STR_FORMAT "xxxx-xx-xx_xx:xx:xx"

#ifdef FUNC_ORIG
char* gettimestr(char* tm_str, int len){
    time_t tm;
    struct tm* ptm;

    if(len < 20){
        printf("Buf len is less than %d\n",sizeof T_STR_FORMAT);return NULL;
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
#endif

char *gettimestr(char *tm_str){
    time_t tm;
    struct tm* pstm;

    tm = time((time_t*)NULL);
    pstm = gmtime(&tm);
    //tm_str = (char *)malloc(sizeof(T_STR_FORMAT));/*此处地址发生变化*/
    snprintf(tm_str,20,"%04d-%02d-%02d_%02d:%02d:%02d",
            pstm->tm_year + 1900,
            pstm->tm_mon + 1,
            pstm->tm_mday,
            pstm->tm_hour + 1,
            pstm->tm_min,
            pstm->tm_sec);
    return tm_str;
}

int main(void)
{
#ifdef FUNC_ORIG
    char string[20];

    printf("sizeof T_STR_FORMAT :%d\n",sizeof T_STR_FORMAT);

    printf("gettimestr: %s\n",gettimestr(string,20));
    printf("[%s] %s\n",__func__,string);
#endif
    char str[20];
    printf("1:%s\n",gettimestr(str));
    printf("2:%s\n",str);

    return 0;
}
