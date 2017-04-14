/*******************************************************************
 *   > File Name: union3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 04:50:19 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool isLendian(void);

int main(int argc, char* argv[])
{
    union Data
    {
        unsigned char a;
        unsigned int b;
    };
    union Data data;
    data.b= 0x12345678;

    if((data.a = 0x12))
        printf("litter-endian\n");
    else
        printf("big-endian\n");

    if(isLendian())
        printf("\t%d\n",isLendian());

    return 0;
}

bool isLendian(void)
{
    union Data{
        unsigned int a;
        unsigned char b;
    }data = {0x12345678};

    if((data.b = 0x12))
        return 1;
    else
        return 0;
}
