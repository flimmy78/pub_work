#ifndef __UARTCAP__H__
#define __UARTCAP__H__
#include <pthread.h>

#define UART_CAP_PROTOCOL_TAIL '~'
#define UART_CAP_PROTOCOL_HEAD "$FG"
#define UART_CAP_PROTOCOL_TYPE1 '&'
#define UART_CAP_PROTOCAL_TYPE2 'H'
#define UART_CAP_PROTOCAL_UP    "UP"
#define UART_CAP_PROTOCAL_DOWN  "DOWN"

#define UART_CAP_SEND_PHOTO_REQ     1
#define UART_CAP_READY_TO_RECV      2
#define UART_CAP_NOT_READY_TO_RECV  3
#define UART_CAP_DATA_BUF_NULL      -1
#define UART_CAP_DATA_BYTE_OVERFLOW -2
#define UART_CAP_CHECK_SUM_ERR      -3
#define UART_CAP_INVALID_PROTOCOL   -5

#define UART_BUFFER_MAX_SIZE        512
#define UART_WR_BUFFER_MAX_SIZE     (30*1024)
#define UART_DATA_BUFFER_MAX_SIZE   (UART_BUFFER_MAX_SIZE >> 3)

#define NOT_READY_TO_RECIEVE        0
#define READY_TO_RECIEVE            1

char UartBuffer[UART_BUFFER_MAX_SIZE];
int UartBufferIndex = 0;

char UartWriteBuffer[UART_WR_BUFFER_MAX_SIZE];
int UartWriteBufindex = 0;

char UartDataBuf[UART_DATA_BUFFER_MAX_SIZE];
int UartDataBufindex = 0;

#define Printf(string...)  \
    do{\
        printf(" %s (%d) [%s]",__FILE__,__LINE__,__func__);\
        printf(string);\
    }while(0)

#pragma pack(push)
#pragma pack(1)

/* 要发送的数据 */
typedef struct _DATA_STR
{
    char* datastr;  //字符串数据
    int datastrlen; //数据长度
}DATA_STR;

typedef struct _UART_CAP_PROTOCOL_FORMAT
{
    const char* headstr;
    char databytes;
    char datatype;
    DATA_STR datastring;
    char checksum;
    const char* tailstr;
}UART_CAP_PROTOCOL_FORMAT;

typedef struct _UART_CAP_WRITE_
{
    char* wrbuf;
    int* wrbufsize;
    int rewitetimes;
    volatile char rewriteover;
}UART_CAP_WRITE;

#pragma pack(pop)

#endif

