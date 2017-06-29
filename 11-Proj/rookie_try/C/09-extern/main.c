/*******************************************************************
 *   > File Name: main.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 26 15:45:29 2017
 ******************************************************************/

#include <stdio.h>

int count;
extern void write_extern();

int main(int argc, char* argv[])
{
    count = 5;
    write_extern();

    return 0;
}
