/*******************************************************************
 *   > File Name: 03-endian.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jul 14 22:37:39 2017
 ******************************************************************/

#include <stdio.h>

void fun(void){
    unsigned int word = 0x12345678;
    unsigned char byte1 = *(unsigned char *)&word;
    unsigned char byte2 = *((unsigned char *)&word + 1);
    unsigned char byte3 = *((unsigned char *)&word + 2);
    unsigned char byte4 = *((unsigned char *)&word + 3);

    printf("%p-->0x%lx--%d\n\n", &word, word, word);

    printf("%p-->0x%hhx--%d\n",&byte1, byte1, byte1);
    printf("%p-->0x%hhx--%d\n",&byte2, byte2, byte2);
    printf("%p-->0x%hhx--%d\n",&byte3, byte3, byte3);
    printf("%p-->0x%hhx--%d\n",&byte4, byte4, byte4);

    if(byte1 == 0x78)
        printf("该机器为小端序！\n");
    else
        printf("该机器为大端序！\n");
}

int main(int argc, char* argv[])
{
    fun();
    return 0;
}
