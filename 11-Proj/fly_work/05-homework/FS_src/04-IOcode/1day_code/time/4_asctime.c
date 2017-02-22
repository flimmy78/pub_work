#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t tm;
    struct tm *tp;

    time(&tm);   //获取时间标准时间

    tp = localtime(&tm);  //将标准时间转换成本地时间
    printf("%s",asctime(tp));  //将本地时间转换成字符串
    return 0;
}
