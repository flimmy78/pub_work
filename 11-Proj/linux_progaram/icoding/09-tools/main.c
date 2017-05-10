/*******************************************************************
 *   > File Name: main.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 10 May 2017 03:50:56 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "a.h"

extern void function_two();
extern void function_three();

int main(int argc, char* argv[])
{
    function_two();
    function_three();

    exit(EXIT_SUCCESS);
}
