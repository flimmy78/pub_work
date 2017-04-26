/*******************************************************************
 *   > File Name: 01-system.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 26 Apr 2017 02:47:28 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Running ps with system");
    system("ps ax");
    printf("Done.\n");
    
    exit(EXIT_SUCCESS);
}
