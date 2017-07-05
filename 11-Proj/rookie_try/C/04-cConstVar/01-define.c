/*******************************************************************
 *   > File Name: 01-define.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年07月04日 星期二 21时17分02秒
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
