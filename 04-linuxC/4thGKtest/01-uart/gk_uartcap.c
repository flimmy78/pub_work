#include "gk_uartcap.h"
#include "gk_uart.h"

int uart_fd;
int g_main_run = 1;

int GK_SetPthreadStackSize(pthread_attr_t* attr, int stacksize)
{
    int pret = -1;

    if((pret = pthread_attr_init(attr)) != 0)  return (-1);
    
    if((pret = pthread_attr_setstacksize(attr, stacksize)) != 0)  return (-1); 

    return 0;
}

void* UartCap_ReadPthread(void* arg)
{
    if(pthread_detach(pthread_self()) != 0)
    {
        Printf("UartCap_ReadPthread detach err\n");    
        return NULL;
    }

    //int ret ;
    g_main_run = 1;
    while(g_main_run)
    {
        static int real_read_size = 0;
        //static int real_write_size = 0;


        real_read_size = gk_read_com_port(uart_fd, UartBuffer + UartBufferIndex, UART_BUFFER_MAX_SIZE);
        if(real_read_size < 0)
        {
            Printf("Read Uart Port Fail\n");
            continue;
        }
        int i = 0;
        for(i = 0;i < real_read_size; i++)
        {
            printf("%c",UartBufferIndex + i);
        }
        UartBufferIndex += real_read_size;
        if(UartBufferIndex >= UART_BUFFER_MAX_SIZE)
        {
            Printf("UartBUffer overflow\n");
            UartBufferIndex = 0;
            continue;
        }
    }

    gk_close_com_port(uart_fd);

}

void* UartCap_WritePthread(void* arg)
{
    if(pthread_detach(pthread_self()) != 0)
    {
        Printf("UartCap_WritePthread detach err\n");
        return NULL;
    }
}

int uartcap_startservice(void)
{
    pthread_t pidrd,pidwr;
    pthread_attr_t attr;
    int ret;
    UART_CONFIG uart_cfg = 
    {
        .UartID = UART_1,
        .BaudRate = 115200,
        .DataBite = 8,
        .Parity = 'N',
        .StopBite = 1
    };
    
    uart_fd = gk_open_com_port(uart_cfg);
    if(uart_fd > 0)
    {
        Printf("Open uart port Ok\n");
    }
    else
    {
        Printf("Open uart port fail\n");
        return (-1);
    }

    GK_SetPthreadStackSize(&attr, 500000);

    /* 串口读写线程 */
    ret = pthread_create(&pidrd, &attr, UartCap_ReadPthread, NULL);
    if(ret < 0)
    {
        Printf("UartCap_ReadPthread err\n");
        return (-1);
    }

    ret = pthread_create(&pidwr, &attr, UartCap_WritePthread, NULL);
    if(ret < 0)
    {
        Printf("UartCap_ReadPthread err\n");
        return (-1);
    }

    return 0;
}

int main(int argc, char* argv[])
{
    uartcap_startservice();

    return 0;
}
