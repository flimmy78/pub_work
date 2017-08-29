/*******************************************************************
 *   > File Name: 03-const.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Aug 23 11:15:06 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;

    area = LENGTH * WIDTH;
    printf("Value of area :%d", area);
    printf("%c", NEWLINE);

    return 0;
}
