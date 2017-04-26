/*******************************************************************
 *   > File Name: 05-upper.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 26 Apr 2017 05:42:54 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{   
    int ch;
    while((ch = getchar()) != EOF){
        putchar(toupper(ch));
    }

    return 0;
}
