/*******************************************************************
 *   > File Name: 01-system.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 01:24:01 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Running ps with system\n");
#if (0)
    system("ps ax");
#else
    system("ps ax &");
#endif
    printf("Done.\n");

    exit(EXIT_SUCCESS);
}
