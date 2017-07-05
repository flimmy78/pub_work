/*******************************************************************
 *   > File Name: 01-const.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年07月04日 星期二 21时23分26秒
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
