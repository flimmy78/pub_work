/*******************************************************************
 *   > File Name: 07-sizeterm.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 04 May 2017 04:42:16 PM CST
 ******************************************************************/

#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int nrows, ncolumns;

    setupterm(NULL, fileno(stdout), (int*)0);
    nrows = tigetnum("lines");

    ncolumns = tigetnum("cols");
    printf("This terminal has %d columns and %d rows\n", ncolumns, nrows);

    return 0;
}
