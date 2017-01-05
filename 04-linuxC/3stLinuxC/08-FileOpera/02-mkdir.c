/*******************************************************************
 *   > File Name: 02-mkdir.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 05 Jan 2017 02:20:26 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PATHNAME "./newDocument"

int main(void)
{
    int retval = 0;
    retval = mkdir(PATHNAME, 0755);
    printf("retval = %d\n",retval);

    return 0;
}
