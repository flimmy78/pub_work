/*******************************************************************
 *   > File Name: 99-ProtocolAnlysis.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 09:19:32 AM CST
 ******************************************************************/

#include <stdio.h>

#define UART_CAP_PROCOTOL_TAIL  '~'     /*头*/
#define UART_CAP_PROCOTOL_HEAD  "$FG"   /*尾*/
#define UART_CAP_PROTOCOL_TYPE1 '&'     /*类型1*/
#define UART_CAP_PROTOCOL_TYPE2 'H'     /*类型2*/
#define UART_CAP_PROCOTOL_UP    "UP"
#define UART_CAP_PROCOTOL_DOWN  "DOWN"

#define UART_CAP_SEND_PHOTO_REQ     1   /*发送图片*/
#define UART_CAP_READY_TO_RECV      2   /*准备好接收*/
#define UART_CAP_NOT_READY_TO_RECV  3   /*未准备好接收*/
#define UART_CAP_DATA_BUF_NULL      -1  /*数据BUF为空*/
#define UART_CAP_DATA_BYTE_OVERLOV  -2  /*BUF溢出*/
#define UART_CAP_CHECK_SUM_ERR      -3  /*校验出错*/
#define UART_CAP_INVALID_PROTOCOL   -4  /*协议无效*/

#pragma pack(push)
#pragma pack(1)
typedef struct _DATA_STR
{
    char* datastr;
    int datastrlen;
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
    int rewritetimes;
    volatile char rewriteover;
}UART_CAP_WRITE;
#pragma pack(pop)

int ProcotolAnlysis(char *data,int datalen)
{
    char* addroffset = NULL;/*字符指针*/
    int datanum = 0;    /*数据位*/
    char checksum = 0,checksum_tmp = 0;/*总和*/
    char datatype = 0;  /*数据类型*/
    DATA_STR datastr;   /*数据*/
    int i = 0;

    if(data == NULL)
    {
        return -1;
    }

    /* 1.找到帧头地址 */
    addroffset = strstr(data,UART_CAP_PROTOCOL_HEAD);
    if(addroffset == NULL)
    {
        Printf("Do not find head from uart data \n");
        return UART_CAP_DATA_BUF_NULL;
    }

    addroffset += strlen(UART_CAP_PROTOCOL_HEAD);   //调过帧头
    datanum = addroffset[0];    //找到数据位
    /*检查数据长度*/
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


int main(int argc, char* argv[])
{
    return 0;
}
