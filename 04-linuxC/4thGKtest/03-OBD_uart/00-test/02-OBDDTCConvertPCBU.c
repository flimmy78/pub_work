/*******************************************************************
 *   > File Name: 02-OBDDTCConvertPCBU.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 17 Jan 2017 11:23:13 AM CST
 ******************************************************************/

#include <stdio.h>

/*2字节故障码转换成标准OBD故障的函数示例*/
void OBDDTCConvertPCBU(unsigned short dtc, char* out_buf)
{
    switch(dtc&0xC000)
    {
        case 0x0000:
            out_buf[0] = 'P';
            break;
        case 0x4000:
            out_buf[0] = 'C';
            break;
        case 0x8000:
            out_buf[0] = 'B';
            break;
        case 0xC000:
            out_buf[0] = 'U';
            break;
    }
#if 0
    out_buf[1] = HalfByte2HexChar((dtc >> 12) & 0x02);
    out_buf[2] = HalfByte2HexChar((dtc >> 8) & 0x0F);
    out_buf[3] = HalfByte2HexChar((dtc >> 4) & 0x0F);
    out_buf[4] = HalfByte2HexChar((dtc >> 0) & 0x0F);
#endif
    out_buf[5] = 0;
    printf("%s\n",out_buf);
}

int main(int argc, char* argv[])
{
    unsigned short a1 = 0;
    unsigned short a2 = 1;
    unsigned short a3 = 2;
    char buf[10];

    OBDDTCConvertPCBU(a1,buf);
    OBDDTCConvertPCBU(a2,buf);
    OBDDTCConvertPCBU(a3,buf);

    return 0;
}
