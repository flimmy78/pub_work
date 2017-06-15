/*******************************************************************
 *   > File Name: 00-time.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 09:42:40 2017
 ******************************************************************/
#if (0)
time_t time(time_t *t);
//此函数会返回从公元 1970 年 1 月 1 日的 UTC 时间从 0 时 0 分 0 秒
//算起到现在所经过的秒数。如果 t 并非空指针的话，此函数也会将
//返回值存到 t 指针所指的内存。
//成功则返回秒数，失败则返回（（time_t）-1）值，错误原因存于 errno
//中
#endif

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    time_t tm, tmp;
    
    if((tm = time(&tmp)) == (-1)){
        printf("get the time as the number of seconds since the Epoch\n");
        exit(EXIT_FAILURE);
    }
    printf("tm = %ld, tmp = %ld\n", tm, tmp);

    return 0;
}
