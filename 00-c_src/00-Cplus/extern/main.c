/*******************************************************************
 *   > File Name: main.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 03:56:21 PM CST
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
