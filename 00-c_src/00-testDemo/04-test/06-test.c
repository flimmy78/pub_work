/*******************************************************************
 *   > File Name: 06-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 05:14:38 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    unsigned long array[] = {0x12345678, 0xabcdef01, 0x456789ab};
    unsigned short ret;

    ret = *((unsigned short *)((unsigned long)array + 7));
    printf("0x%x\n", ret);

    return 0;
}
