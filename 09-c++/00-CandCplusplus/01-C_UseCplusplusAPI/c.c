/*******************************************************************
 *   > File Name: c.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Nov 24 18:29:29 2017
 ******************************************************************/

#include <stdio.h>
//#include "cpp.h"

extern int add(int x, int y);
int main(int argc, char* argv[])
{
    printf("add(5 , 8) = %d\n", add(5,8));
    return 0;
}
