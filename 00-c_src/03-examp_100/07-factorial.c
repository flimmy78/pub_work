/*******************************************************************
 *   > File Name: 07-factorial.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jan  9 13:42:06 2018
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a, count = 0;

    for(a=5; a<=100; a+=5){
        /*循环从5开始，以5的倍数为步长，考察整数*/
        count ++;   /*若为5的倍数，计数器加1*/
        if(!(a % 25))
            count++;    /*若为25的倍数，计数器再加1*/
    }

    printf("The number of 0 in the end of 100! is :%d.\n", count);
    return 0;
}
