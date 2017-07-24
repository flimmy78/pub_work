/*******************************************************************
 *   > File Name: 03-endian.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Jul 2017 10:06:19 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool is_little_endian(void){
    bool ret;
    unsigned int word = 0x12345678;
    unsigned char byte0 = *((unsigned char *)&word + 0);
    unsigned char byte1 = *((unsigned char *)&word + 1);
    unsigned char byte2 = *((unsigned char *)&word + 2);
    unsigned char byte3 = *((unsigned char *)&word + 3);

    printf("%p---->0x%hhx\n",&byte0, byte0);
    printf("%p---->0x%hhx\n",&byte1, byte1);
    printf("%p---->0x%hhx\n",&byte2, byte2);
    printf("%p---->0x%hhx\n",&byte3, byte3);

    if(byte0 == 0x78){
        printf("the machine is little endian !\n");
        ret = 1;
    }else if(byte0 == 0x12){
        printf("the machine is big endian !\n");
        ret = 0;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    is_little_endian();
    return 0;
}
