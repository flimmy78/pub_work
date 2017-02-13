/*******************************************************************
 *   > File Name: 99-ProtocolAnalysis.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 05:37:58 PM CST
 ******************************************************************/

#include <stdio.h>

int ProcotolAnalysis(char *data,int datalen)
{
    char* addroffset = NULL;
    int datanum = 0;
    char checksum = 0, checksum_tmp = 0;
    char datatype = 0;
    DATA_STR datastr;
    int i;

    if(data == NULL)
    {
        return (-1);
    }

    /*找到帧头地址*/
    addroffset = strstr(data, UART_CAP_PROTOCAL_HEAD);
    if(addroffset == NULL)
    {
        printf("do not find head from uart data\n");
        return UART_CAP_DATA_BUF_BULL;
    }

    addroffset += strlen(UART_CAP_PROTOCOL_HEAD);
    datasum = addroffset[0];/*数据位数*/

    if(strlen(UART_CAP_PROTOCOL_HEAD) + 1 + datanum + 1 > datalen)
    {
        printf("data num err\n");
        return UART_CAP_DATA_BYTE_OVERLOV;
    }
    checksum = addroffset[adatanum];

    for(i = 0; i < datasum; i++)
    {
        checksum_tmp 
    }
}

int main(int argc, char* argv[])
{
    return 0;
}
