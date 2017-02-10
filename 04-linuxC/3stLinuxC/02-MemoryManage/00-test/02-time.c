/*******************************************************************
 *   > File Name: 02-time.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 02:04:12 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t tm1,tm2;

    tm1 = time(&tm2);
    printf("tm1 = %ld\n",tm1);
    printf("tm2 = %ld\n",tm2);
    printf("ctime(&tm1) :%s",ctime(&tm1));
    printf("ctime(&tm2) :%s\n",ctime(&tm2));

    return 0;
}
