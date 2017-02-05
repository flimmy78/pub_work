/*******************************************************************
 *   > File Name: 09-gettimestr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 11:07:18 AM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

int gettimestr(char* tm_str, int len)
{
    time_t tm;
    struct tm* ptm;
    
    if(len < 20)
    {
        printf("[%s] BufLen is less than 20 bytes\n",__func__);
        return (-1);
    }

    time(&tm);
    ptm = gmtime(&tm);
    snprintf(tm_str, len,"%04d-%02d-%02d_%02d:%02d:%02d",
            ptm -> tm_year + 1900,
            ptm -> tm_mon + 1,
            ptm -> tm_mday,
            ptm -> tm_hour + 8,
            ptm -> tm_min,
            ptm -> tm_sec);
#if (0)
    printf("tm_str = %p\n",tm_str);
    printf("[%s] %s\n",__func__,tm_str);
    int i;
    for(i = 0; i < 19; i++)
    {
        printf("%d-%c\n",i,tm_str[i]);
    }
#endif
    return 0;
}

int main(void)
{
    char str[25];
    int ret;
    ret = gettimestr(str,20);
    printf("[%s] %s\n",__func__,str);
    return 0;
}
