/*******************************************************************
 *   > File Name: 01-runTime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Jul 2017 08:35:44 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int i;

    for(i = 0; i< 3; i++){
        printf("loop %d\n", i);
        sleep(1);
    }

    return 0;
}
