/*******************************************************************
 *   > File Name: 02-define.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Aug 23 10:26:30 2017
 ******************************************************************/

#include <stdio.h>

#define LENGTH  10
#define WIDTH   5
#define NEWLINE '\n'

int main(int argc, char* argv[])
{
    int area;

    area = LENGTH * WIDTH;
    printf("Value of area :%d", area);
    printf("%c", NEWLINE);

    return 0;
}
