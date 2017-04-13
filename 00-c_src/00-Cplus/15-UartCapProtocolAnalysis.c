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

void* UartCap_ServicePthread(void *arg)
{
    int real_read_size = 0;
    int real_write_size = 0;

    real_read_size = gk_read_com_port(uart_fd, UartBuffer+UartBufferIndex,UART_BUFFER_MAX_SIZE);
    if(real_read_size < 0)
    {
        Printf("Read Uart Port Fail\n");
        continue;
    }

    int i = 0;
    for(i = 0; i<real_read_size; i++)
    {
        printf("%c",UartBuffer[UartBufferIndex + i]);
    }
    printf("\n");
    UartBUfferIndex += real_read_size;

    if(UartBufferIndex >= UART_BUFFER_MAX_SIZE)
    {
        Printf("UartBuffer OverLow\n");
        UartBufferIndex = 0;
        continue;
    }
    
    if(UartBuffer[UartBufferIndex - 1] == UART_CAP_PROTOCOL_TAIL)
    {
        ret = UartCapProtocolAnalysis(UartBuffer, UartBufferIndex);
        switch(ret)
        {
            case UART_CAP_SEND_PHOTO_REQ:

        }
    }
}
