/*******************************************************************
 *   > File Name: 06-envtime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 09:14:16 AM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int i;
    time_t the_time;

    for(i = 0; i < 10; i++){
        the_time = time((time_t *)NULL);
        printf("The time is :%ld \n",the_time);
        sleep(2);
    }

    return 0;
}
