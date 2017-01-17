/*******************************************************************
 *   > File Name: 01-crc32.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 17 Jan 2017 11:15:42 AM CST
 ******************************************************************/

#include <stdio.h>

/*CRC32函数示例*/
unsigned int SoftwareCRC32(unsigned int data[], unsigned int size)
{
    unsigned int i, j, temp, crc = 0xFFFFFFFF;

    for(i = 0; i<size; i++)
    {
        temp = data[i];
        for(j = 0; j<32; j++)
        {
            if(((crc ^ temp) & 0x80000000) != 0)
            {
                crc = 0x04C11DB7 ^ (crc << 1);
            }
            else
            {
                crc <<= 1;
            }
            temp <<= 1;
        }
    }
    return crc;
}

int main(int argc, char* argv[])
{
    return 0;
}
