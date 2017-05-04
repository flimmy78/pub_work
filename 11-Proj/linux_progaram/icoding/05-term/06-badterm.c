/*******************************************************************
 *   > File Name: 06-setupterm.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 04 May 2017 04:34:16 PM CST
 ******************************************************************/

#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    setupterm("unlisted", fileno(stdout), (int*)0);
    printf("Done.\n");

    return 0;
}
