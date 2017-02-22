#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t tm;
    int ret;
    ret = time(&tm);   //获取时间标准时间
    printf("ret = %d\n",ret);
    printf("tm= %ld\n",tm);
    return 0;
}
