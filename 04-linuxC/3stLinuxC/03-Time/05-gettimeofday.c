/*******************************************************************
 *   > File Name: 05-gettimeofday.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 09 Jan 2017 09:32:47 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    struct timeval nowTV;
    struct timezone nowTZ;
    gettimeofday(&nowTV, &nowTZ);
    printf("%ld--%ld\n",nowTV.tv_sec,nowTV.tv_usec);
    printf("%d--%d\n",nowTZ.tz_minuteswest,nowTZ.tz_dsttime);

    return 0;
}
