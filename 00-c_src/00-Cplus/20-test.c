/*******************************************************************
 *   > File Name: 20-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 16 Feb 2017 12:26:42 AM CST
 ******************************************************************/
#include <stdio.h>

int main(void)
{
#if 0
    unsigned short i;
    unsigned short index = 0;
    for(i=0; i<index - 1;i++)
    {
        printf("hehe\n");
    }
#else 
    unsigned short i;
    unsigned long index = 0;
    for(i=0; i<index-1 ;i++)
    {
        printf("\tb\n");
    }
#endif

    return 0;
}

