/*******************************************************************
 *   > File Name: 05-upper.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 03:43:29 PM CST
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
    
    exit(EXIT_SUCCESS);
}
