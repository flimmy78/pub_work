/*******************************************************************
 *   > File Name: 05-alarm_pause.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 03:19:54 PM CST
 ******************************************************************/
/*头文件*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    /*调用alarm定时器*/
    alarm(5);
    pause();
    printf("I have been waken up.\n");/*此语句不会被执行*/


    return 0;
}
