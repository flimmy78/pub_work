#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t tm;

    time(&tm);   //获取时间标准时间

    printf("%s",ctime(&tm));
    return 0;
}
