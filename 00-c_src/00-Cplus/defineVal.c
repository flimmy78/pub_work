/*******************************************************************
 *   > File Name: defineVal.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 03:44:32 PM CST
 ******************************************************************/

#include <stdio.h>

#define LENGTH      10
#define WIDTH       5
#define NEWLINE     '\n'

int main(int argc, char* argv[])
{
    int area;

    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);

    return 0;
}
