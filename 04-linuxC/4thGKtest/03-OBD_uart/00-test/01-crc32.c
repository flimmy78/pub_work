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
    int a[] = {1,2,3,4,5,6,7,8,9,1};
    int b[] = {0,2,3,4,5,6,7,8,9,255};
    int c[] = {1,2,3,4,5,6,7,8,9,0};
    //printf("size = %d\n",sizeof a);
    int size = (sizeof a)/sizeof(int);
    //printf("size = %d\n",size);
    int ret;
    ret = SoftwareCRC32(a,size);
    int ret1 = SoftwareCRC32(b,size);
    int ret2 = SoftwareCRC32(c,size);
    printf("ret = %d\tret1 = %d\tret2 = %d\n",ret,ret1,ret2);
    return 0;
}
