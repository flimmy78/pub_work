/*******************************************************************
 *   > File Name: 22-bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 03:06:31 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc > 3 || argc < 3){
        printf("\tUsage :%s  <Integer>  <bitNum>\n",argv[0]);return 0;
    }

    int value, bit;
    
    value = atoi(argv[1]), bit = atoi(argv[2]);
    printf("value = %d  bit = %d\n",value, bit);

    value = value >> bit;
    printf("--->value  = %d\n", value);

    return 0;
}
