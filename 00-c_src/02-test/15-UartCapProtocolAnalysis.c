/*******************************************************************
 *   > File Name: 15-UartCapProtocolAnalysis.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 04 Jan 2017 11:00:59 AM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    return 0;
}

int UartCapProtocolAnalysis(char *data, int datalen)
{
    char* addroffset = NULL;
    int datanum = 0;
    char checksum = 0,checksum_tmp = 0;
    char datatype = 0;

    DATA_STR datastr;

    int i = 0;

    if(data == NULL)
    {
        return (-1);
    }

    addroffset = strstr(data,UART_CAP_PROTOCOL_HEAD);
    if(addroffset == NULL)
    {
        printf("Don`t fine head from uart data");
        return UART_CAP_DATA_BUF_NULL;
    }

    addroffset += strlen(UART_CAP_PROTOCOL_HEAD);
    datanum = addroffset[0];
    if(strlen(UART_CAP_PROTOCOL_HEAD) + 1 + datanum +1 > datalen)
    {
        printf("data num error\n");  
    }
}
