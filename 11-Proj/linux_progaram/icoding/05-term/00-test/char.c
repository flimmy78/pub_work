/*******************************************************************
 *   > File Name: char.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 07 Apr 2017 03:59:07 PM CST
 ******************************************************************/

#include <stdio.h>

char *menu[] = {
    "a - add some info",
    "b - list all info",
    "c - del some info",
    NULL,
};

int main(int argc, char* argv[])
{
    printf("%s\n", *menu);
    printf("%s\n", *(menu + 1));
    printf("%s\n", *(menu + 2));
    //printf("%s\n", *(menu + 3));
    return 0;
}
