/*******************************************************************
 *   > File Name: union0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 04:15:00 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

union Data
{
    int i;
    float f;
    char str[20];
};

int main(int argc, char* argv[])
{
    union Data data;

    printf("Memory size occupied by data :%d\n", sizeof(data));

    return 0;
}
