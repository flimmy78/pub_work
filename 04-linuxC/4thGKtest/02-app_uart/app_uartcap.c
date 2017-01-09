//#include "app_misc.h"

#include "app_uartcap.h"



char	UartBuffer[UART_BUFFER_MAX_SIZE];
int UartBufferIndex = 0;

char UartWriteBuffer[UART_WR_BUFFER_MAX_SIZE];
int UartWriteBufindex = 0;

char UartDataBuf[UART_DATA_BUFFER_MAX_SIZE];
int UartDataBufindex = 0;

int uart_fd = 0;

UART_CAP_PROTOCOL_FORMAT UartCapBuffer;
UART_CAP_WRITE	UartWriteBufPointer;

const char tail = UART_CAP_PROTOCOL_TAIL;

int GK_SetPthreadStackSize(pthread_attr_t *attr, int stacksize)
{
    int pret = -1;

    if((pthread_attr_init(attr)) != 0)
        return (-1);
    if((pthread_attr_setstacksize(attr, stacksize)) != 0)
        return (-1);
    return 0;
}

int UartCapProtocolAnalysis(char* data,int datalen)
{
    char*addroffset = NULL;
    int datanum = 0;
    char checksum = 0,checksum_tmp = 0;
    char datatype = 0;
    DATA_STR datastr;
    int i = 0;

    if(data == NULL)
    {
        return -1;
    }

    addroffset = strstr(data,UART_CAP_PROTOCOL_HEAD);
    if(addroffset == NULL)
    {
        Printf("Do not find head from uart data \n");
        return UART_CAP_DATA_BUF_NULL;
    }

    addroffset += strlen(UART_CAP_PROTOCOL_HEAD);
    datanum = addroffset[0];
    if(strlen(UART_CAP_PROTOCOL_HEAD) + 1 + datanum + 1 > datalen)
    {
        Printf("data num error \n");
        return UART_CAP_DATA_BYTE_OVERLOV;
    }
    checksum = addroffset[datanum];

    for(i=0; i < datanum; i ++)
    {
        checksum_tmp += addroffset[i];
    }
    if(checksum != checksum_tmp)
    {
        Printf("check sum fail \n");
        return UART_CAP_CHECK_SUM_ERR;
    }

    datatype = addroffset[1];
    if(datatype == UART_CAP_PROTOCOL_TYPE1)
    {
        return UART_CAP_SEND_PHOTO_REQ;
    }
    else if(datatype == UART_CAP_PROTOCOL_TYPE2)
    {
        datastr.datastr = addroffset[2];
        datastr.datastrlen = datanum - 2;
        if(datastr.datastr[0] == READY_TO_RECIEVE)
        {
            return UART_CAP_READY_TO_RECV;
        }
        else
        {
            return UART_CAP_NOT_READY_TO_RECV;
        }
    }
    else
    {
        Printf("invalid data \n");
        return UART_CAP_INVALID_PROTOCOL;
    }
}

int UartCapProtocolDataReady(char* databuf,int databuflen,void* data)
{
    int databufindex = 0,ret = 0;;

    UART_CAP_PROTOCOL_FORMAT* datatmp = (UART_CAP_PROTOCOL_FORMAT*)data;

    if(databuf == NULL || data == NULL)
    {
        Printf("data buf null \n");
        return UART_CAP_DATA_BUF_NULL;
    }

    databufindex = strlen(datatmp->headstr);
    memcpy(databuf,datatmp->headstr,databufindex);

    databuf[databufindex] = datatmp->databytes;
    databufindex += sizeof(datatmp->databytes);

    databuf[databufindex] = datatmp->datatype;
    databufindex += sizeof(datatmp->datatype);

    if(datatmp->datastring.datastr)
    {
        if(databufindex + datatmp->datastring.datastrlen >= databuflen)
        {
            Printf("data buf overlow \n");
            return UART_CAP_DATA_BYTE_OVERLOV;
        }
        memcpy(databuf + databufindex,datatmp->datastring.datastr,datatmp->datastring.datastrlen);
        databufindex += datatmp->datastring.datastrlen;
    }

    databuf[databufindex] = datatmp->checksum;
    databufindex += sizeof(datatmp->checksum);

    databuf[databufindex]= datatmp->tailstr[0];
    databufindex += 1;

    return databufindex;
}

int UartCapProtocolCheckSumCalc(void* data)
{
    int i = 0;
    UART_CAP_PROTOCOL_FORMAT* datatmp = (UART_CAP_PROTOCOL_FORMAT*)data;

    if(data == NULL)
    {
        Printf("data buf null \n");
        return UART_CAP_DATA_BUF_NULL;
    }

    datatmp->checksum = datatmp->databytes;
    datatmp->checksum += datatmp->datatype;
    for(i=0; i<datatmp->datastring.datastrlen; i++)
    {
        datatmp->checksum += datatmp->datastring.datastr[i];
    }

    return 0;
}

#define	debug
void* UartCap_ServicePthread(void* arg)
{
    int ret = 0;
    char datastr[32];

    g_main_run=1;
    while(g_main_run)
    {
        int real_read_size = 0;
        int real_write_size = 0;

        /*从串口读取数据*/
        real_read_size = gk_read_com_port(uart_fd,UartBuffer+UartBufferIndex,UART_BUFFER_MAX_SIZE);
        if(real_read_size < 0)
        {
            Printf("Read Uart Port Fail \n");
            continue;
        }
        int i=0;
        for(i=0; i<real_read_size; i++)
        {
            printf("%c",UartBuffer[UartBufferIndex+i]);
        }
        printf("\n");
        UartBufferIndex += real_read_size;
#ifdef debug
        if(UartBufferIndex >3)
        {
            if(strcmp(UartBuffer + UartBufferIndex -4,"hello") == 0)
            {
                UartCapBuffer.databytes = 8;
                UartCapBuffer.datatype = '&';
                snprintf(datastr,32,"%d%c",30720,'\0');
                UartCapBuffer.datastring.datastr = datastr;
                UartCapBuffer.datastring.datastrlen = strlen(datastr);
                if(UartCapProtocolCheckSumCalc(&UartCapBuffer) < 0)
                {
                    Printf("Uart cap check sum fail \n");
                    UartBufferIndex = 0;
                    continue;
                }
                UartDataBufindex = UartCapProtocolDataReady(UartDataBuf,UART_DATA_BUFFER_MAX_SIZE,
                                   &UartCapBuffer);
                if(UartDataBufindex < 0)
                {
                    Printf("Ready uart write data fail \n");
                    UartBufferIndex = 0;
                    continue;
                }
                UartWriteBufPointer.rewritetimes = 0;
                while(UartWriteBufPointer.rewriteover == 0)
                {
                    usleep(100*1000);
                }
                UartWriteBufPointer.wrbuf = UartDataBuf;
                UartWriteBufPointer.wrbufsize = &UartDataBufindex;
                UartWriteBufPointer.rewritetimes = 3;
            }
        }
#endif
        if(UartBufferIndex >= UART_BUFFER_MAX_SIZE)
        {
            Printf("UartBuffer OverLow \n");
            UartBufferIndex = 0;
            continue;
        }

        if(UartBuffer[UartBufferIndex -1] == UART_CAP_PROTOCOL_TAIL)
        {
            ret = UartCapProtocolAnalysis(UartBuffer,UartBufferIndex);
            switch(ret)
            {
            case UART_CAP_SEND_PHOTO_REQ:
            {
                UartCapBuffer.databytes = 8;
                UartCapBuffer.datatype = 'H';
                snprintf(datastr,32,"%d%c",30720,'\0');
                UartCapBuffer.datastring.datastr = datastr;
                UartCapBuffer.datastring.datastrlen = strlen(datastr);
                if(UartCapProtocolCheckSumCalc(&UartCapBuffer) < 0)
                {
                    Printf("Uart cap check sum fail \n");
                    UartBufferIndex = 0;
                    continue;
                }
                UartDataBufindex = UartCapProtocolDataReady(UartDataBuf,UART_DATA_BUFFER_MAX_SIZE,
                                   &UartCapBuffer);
                if(UartDataBufindex < 0)
                {
                    Printf("Ready uart write data fail \n");
                    UartBufferIndex = 0;
                    continue;
                }
                UartWriteBufPointer.rewritetimes = 0;
                while(UartWriteBufPointer.rewriteover == 0)
                {
                    usleep(100*1000);
                }
                UartWriteBufPointer.wrbuf = UartDataBuf;
                UartWriteBufPointer.wrbufsize = &UartDataBufindex;
                UartWriteBufPointer.rewritetimes = 3;
                break;
            }
            case UART_CAP_READY_TO_RECV:
            {
                UartWriteBufPointer.rewritetimes = 0;
                while(UartWriteBufPointer.rewriteover == 0)
                {
                    usleep(100*1000);
                }
                int photo_fd = open("/debug.jpg",O_RDONLY);
                if(photo_fd < 0)
                {
                    Printf("open photo fail \n");
                    memset(UartWriteBuffer,'a',UART_WR_BUFFER_MAX_SIZE);
                }
                else
                {
                    UartWriteBufindex = read(photo_fd,UartWriteBuffer,UART_WR_BUFFER_MAX_SIZE);
                    if(UartWriteBufindex < 0)
                    {
                        Printf("read photo fail \n");
                        memset(UartWriteBuffer,'a',UART_WR_BUFFER_MAX_SIZE);
                    }
                }

                UartWriteBufPointer.wrbuf = UartWriteBuffer;
                UartWriteBufPointer.wrbufsize = &UartWriteBufindex;
                UartWriteBufPointer.rewritetimes = 3;
                break;
            }
            case UART_CAP_NOT_READY_TO_RECV:
            {
                UartWriteBufPointer.rewritetimes = 0;
                while(UartWriteBufPointer.rewriteover == 0)
                {
                    usleep(100*1000);
                }
                UartWriteBufPointer.wrbuf = UartDataBuf;
                UartWriteBufPointer.wrbufsize = &UartDataBufindex;
                UartWriteBufPointer.rewritetimes = 3;
                break;
            }
            default:
                break;
            }
            UartBufferIndex = 0;
        }
        else
        {
            continue;
        }

    }

    gk_close_com_port(uart_fd);
}

void* UartCap_writePthread(void* arg)
{
    int real_write_size = 0;
    char shutflag = 0;
    char datastr[32];

    g_main_run=1;
    while(g_main_run)
    {
        shutflag = gk_get_shut_up_down();
        if(shutflag == SHUT_UP_HANDLE || shutflag == SHUT_DOWN_HANDLE)
        {
            UartCapBuffer.datatype = UART_CAP_PROTOCOL_TYPE2;
            UartCapBuffer.datastring.datastr = datastr;

            if(shutflag == 1)
            {
                UartCapBuffer.datastring.datastrlen = strlen(UART_CAP_PROTOCOL_UP);
                memcpy(UartCapBuffer.datastring.datastr,UART_CAP_PROTOCOL_UP,
                       UartCapBuffer.datastring.datastrlen);
            }
            else
            {
                UartCapBuffer.datastring.datastrlen = strlen(UART_CAP_PROTOCOL_DOWN);
                memcpy(UartCapBuffer.datastring.datastr,UART_CAP_PROTOCOL_DOWN,
                       UartCapBuffer.datastring.datastrlen);
            }

            UartCapBuffer.databytes = 1 + UartCapBuffer.datastring.datastrlen + 1;
            UartCapProtocolCheckSumCalc(&UartCapBuffer);
            UartDataBufindex = UartCapProtocolDataReady(UartDataBuf,UART_WR_BUFFER_MAX_SIZE,
                               &UartCapBuffer);
            if(UartWriteBufindex < 0)
            {
                Printf("get ready data to write fail \n");
                sleep(1);
                continue;
            }

            UartWriteBufPointer.wrbuf = UartDataBuf;
            UartWriteBufPointer.wrbufsize = &UartDataBufindex;
            UartWriteBufPointer.rewritetimes = 10;

            gk_set_shut_up_down(SHUT_UP_DOWN_IDLE);
        }

        if(UartWriteBufPointer.rewritetimes)
        {
            if(UartWriteBufPointer.wrbuf == NULL || UartWriteBufPointer.wrbufsize == NULL)
            {
                UartWriteBufPointer.rewritetimes = 0;
                sleep(1);
                continue;
            }
            UartWriteBufPointer.rewriteover = 0;
            /* 往串口写数据*/
            real_write_size = gk_write_com_port(uart_fd,UartDataBuf,UartDataBufindex);
            if(real_write_size < 0)
            {
                Printf("Write uart data fail \n");
                sleep(1);
                continue;
            }
            UartWriteBufPointer.rewriteover = 1;
            UartWriteBufPointer.rewritetimes --;
            Printf("Shut Up Down Ready to Write %d \n",UartWriteBufPointer.rewritetimes);
        }
        sleep(1);
    }
}

int uartcap_startservice(void)
{
    pthread_t pid,pidwr;
    pthread_attr_t attr;
    int ret;
    UART_CONFIG uart_cfg =
    {
        .UartID = UART_2,
        .BaundRate = 115200,
        .DataBite = 8,
        .Parity = 'N',
        .StopBite = 1
    };

    UartCapBuffer.headstr = UART_CAP_PROTOCOL_HEAD;
    UartCapBuffer.tailstr = &tail;

    uart_fd = gk_open_com_port(uart_cfg);
    if(uart_fd > 0)
    {
        Printf("open uart port successful \n");
    }
    else
    {
        Printf("open uart port fail fd = %d \n",uart_fd);
        return -1;
    }

    GK_SetPthreadStackSize(&attr, 500000);
    ret = pthread_create(&pid, &attr, UartCap_ServicePthread, NULL);
    if (ret < 0)
    {
        Printf("UartCap_ServicePthread err!\n");
        return -1;
    }
#if 1
    ret = pthread_create(&pidwr, &attr, UartCap_writePthread, NULL);
    if (ret < 0)
    {
        Printf("UartCap_RewritePthread err!\n");
        return -1;
    }
#endif
    return 0;

}
