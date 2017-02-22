#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t tm;
    struct tm *tp;

    time(&tm);   //获取时间标准时间

    tp = localtime(&tm);  //将标准时间转换成本地时间
    printf("%d-%d-%d %d:%d:%d\n",tp->tm_year+1900,tp->tm_mon+1,\
	    tp->tm_mday,tp->tm_hour,tp->tm_min,tp->tm_sec);
    return 0;
}
