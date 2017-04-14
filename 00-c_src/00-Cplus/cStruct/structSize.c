/*******************************************************************
 *   > File Name: structSize.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 02:03:07 PM CST
 ******************************************************************/
#if (0)
结构体占用存储空间,以32位机为例
1.debug_size1_t 存储空间分布为a(1byte)+空闲(3byte)+b(4byte)+c(1byte)+空闲(3byte)=12(byte)。
1.debug_size2_t 存储空间分布为a(1byte)+b(1byte)+空闲(2byte)+c(4byte)=8(byte)。
#endif

#include <stdio.h>

typedef struct
{
    unsigned char a;
    unsigned int b;
    unsigned char c;
}debug_size1_t;

typedef struct
{
    unsigned char a;
    unsigned char b;
    unsigned int c;
}debug_size2_t;

int main(int argc, char* argv[])
{
    printf("debug_size1_t size = %d, debug_size2_t size = %d\r\n",\
            sizeof(debug_size1_t), sizeof(debug_size2_t));

    return 0;
}
