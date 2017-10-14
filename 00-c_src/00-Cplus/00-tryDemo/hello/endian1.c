/*******************************************************************
 *   > File Name: endian1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 05:02:58 PM CST
 ******************************************************************/

#include <stdio.h>

union A{
    unsigned int word;
    unsigned char byte;
};

int main(int argc, char* argv[])
{
    union A un;

    un.word = 0x12345678;
    if(un.byte == 0x78){
        printf("the machine is little endian !\n");
    }else if(un.byte == 0x12){
        printf("the machine is big endian !\n");
    }

    return 0;
}
