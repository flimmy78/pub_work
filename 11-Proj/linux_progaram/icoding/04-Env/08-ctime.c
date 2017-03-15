/*******************************************************************
 *   > File Name: 08-ctime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 10:43:09 AM CST
 ******************************************************************/
#if (0)
time_t time(time_t *t);
char *ctime(const time_t *timep);
#endif

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t the_time;

    time((time_t *)&the_time);
    printf("%s\n",ctime(&the_time));

    return 0;
}
