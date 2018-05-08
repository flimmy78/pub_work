/*******************************************************************
 *   > File Name: 04-alarm_pause.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 03 Jan 2018 08:42:36 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /*调用alarm定时器*/
    alarm(5);
    pause();

    /*以下语句不会执行*/
    printf("I have been wakene up.\n");

    return 0;
}
