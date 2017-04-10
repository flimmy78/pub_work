/*******************************************************************
 *   > File Name: 99-memset.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 03:24:33 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char temp[10];
    printf("%d\n", sizeof(temp));
    memset((void*)temp, 0, sizeof(temp));

    return 0;
}
