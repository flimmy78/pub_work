/*******************************************************************
 *   > File Name: 02-baud_rate.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Wed 28 Dec 2016 03:42:10 PM CST
 ******************************************************************/

#include <stdio.h>

#define    B57600 0010001
#define   B115200 0010002
#define   B230400 0010003
#define   B460800 0010004
#define   B500000 0010005
#define   B576000 0010006
#define   B921600 0010007
#define  B1000000 0010010
#define  B1152000 0010011
#define  B1500000 0010012
#define  B2000000 0010013
#define  B2500000 0010014
#define  B3000000 0010015
#define  B3500000 0010016
#define  B4000000 0010017 

int main(void)
{
    unsigned int speed;
    speed = B115200;
    printf("speed = %d\n",speed);

    return 0;
}
