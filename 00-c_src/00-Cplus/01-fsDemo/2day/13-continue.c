/*******************************************************************
 *   > File Name: 13-continue.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 10:01:49 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    
    i = 0;

    while(i < 10){
        i++;
        if(i % 2 == 0){
            continue;   //执行该语句时，后面的不再执行
        }
        printf("i = %d\n", i);
    }

    return 0;
}
