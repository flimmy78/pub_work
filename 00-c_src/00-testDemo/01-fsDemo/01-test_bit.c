/*******************************************************************
 *   > File Name: 01-test_bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 31 Dec 2016 06:46:21 PM CST
 ******************************************************************/

#include <stdio.h>

void charTobin(char byte);

int main(void)
{
    char a = 5, b = 3;
    charTobin(a);
    charTobin(b);

    return 0;
}

void charTobin(char byte)
{
    int arr[8],i = 0;

    for(i = 0; i < 8; i++)
    {
        arr[i] = byte|(1 >> i);
    }

    for(i = 7; i >= 0; i++)
    {
        printf("%d",arr[i]);
    }
    puts("");
}
