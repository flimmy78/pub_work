/*******************************************************************
 *   > File Name: 21-bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 02:57:37 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc > 2 || argc < 2){
        printf("\n\tUsage: %s <integer> \n\n",argv[0]);return (-1);
    }

    int value = atoi(argv[1]);
    printf("value :%d\n",value);

    int bit3Value, remValue;
    bit3Value = value >> 3;
    remValue  = value % 8;
    printf("bit3Value = %d  remValue = %d\n",bit3Value, remValue);

    return 0;
}
