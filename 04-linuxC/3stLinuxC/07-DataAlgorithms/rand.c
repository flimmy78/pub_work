/*******************************************************************
 *   > File Name: rand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 17:37:57 2017
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("%d\n", rand());
    printf("%f\n", 10.0*rand());
    printf("%f\n", RAND_MAX + 1.0);
    printf("%f\n", 10.0*rand()/(RAND_MAX + 1.0));
    printf("%d\n", (int)(10.0*rand()/(RAND_MAX + 1.0)));

    return 0;
}
