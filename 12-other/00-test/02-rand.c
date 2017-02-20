/*******************************************************************
 *   > File Name: 02-rand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 20 Feb 2017 02:14:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int value = 0;
    int i;

    srand(time(NULL));
    for(i = 0; i< 10; i++)
    {
        value = (int)(rand() * 9.0/(RAND_MAX));
        printf("%d  ",value);
    }
    puts("");


    return 0;
}
