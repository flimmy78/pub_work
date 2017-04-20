/*******************************************************************
 *   > File Name: defineVal.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 03:44:32 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{   
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;

    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);

    return 0;
}
