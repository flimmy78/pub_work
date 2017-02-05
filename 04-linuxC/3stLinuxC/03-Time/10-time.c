/*******************************************************************
 *   > File Name: 10-time.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 05:56:35 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

int main(void)
{
    int S_time = 0,E_time = 0;
    
    S_time = time((time_t*)NULL);
    sleep(10);
    E_time = time((time_t*)NULL);

    printf("(E_time - S_time) = %d sec\n",E_time - S_time);
    return 0;
}
