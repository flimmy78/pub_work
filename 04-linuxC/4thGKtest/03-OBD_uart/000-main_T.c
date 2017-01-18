/*******************************************************************
 *   > File Name: 00-main_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 18 Jan 2017 01:41:26 PM CST
 ******************************************************************/

#include <stdio.h>
#include "common_used.h"

int main(int argc, char* argv[])
{
    Printf("1\n");
    Printd("2\n");
    BEGIN_DEBUG_PRINT("3");
    END_DEBUG_PRINT("4");
    ERR_PRINT("5","6 %d\n",1000);
    return 0;
}
