/*******************************************************************
 *   > File Name: 07-ZeroTotal.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Thu 05 Jan 2017 10:56:27 PM CST
 ******************************************************************/

#include <stdio.h>

/* 100!的末尾有多少个零  */

int main(void)
{
    int a, count = 0;
    for(a = 5; a <= 100; a+=5)  /*循环从5开始，以5的倍数为步长，考察整数*/
    {
        count ++;               /*若为5的倍数，计数器加1*/
        if(!(a%25))             /*若为25的倍数，计数器再加1*/
            count ++;
    }
    printf("The number of 0 in the end of 100! is : %d .\n",count); //若为25的倍数，计数器再加1

    return 0;
}
