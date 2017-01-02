/*******************************************************************
 *   > File Name: 05-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 04:37:38 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    union ENDIAN
    {
        int word ;
        char byte;
    }ENDIAN_;
    ENDIAN_.word = 0x12345678;

    printf("word = 0x%x, byte = 0x%x\n",ENDIAN_.word,ENDIAN_.byte);

    return 0;
}
