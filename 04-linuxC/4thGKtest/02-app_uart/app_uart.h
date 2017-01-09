#ifndef __UART__H__
#define __UART__H__

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>

#define     UART_ERR_OPEN_FAIL      -1
#define     UART_ERR_CONFIG_FAIL    -2

#define BUFFER_SIZE 128
#define HOST_COM_PORT 2
#define MAX_COM_NUM 3
#define GENERAL 1
#define USBTTY 0
#define COM_TYPE 1

typedef enum{
    UART_0  =   0,
    UART_1,
    UART_2,
    UART_NUM
}UART_ID;

typedef struct{
    int UartID;
    int BaudRate;
    int DataBite;
    int Parity;
    int StopBite;
}UART_CONFIG;

int open_port(int com_port);
int set_com_config(int fd,int baud_rate,int data_bits,char parity,int stop_bits);

signed int gk_open_com_port(UART_CONFIG uart_config);
signed int gk_close_com_port(int fd);
signed int gk_read_com_port(signed int fd,char *read_buf,int read_size);
signed int gk_write_com_port(signed int fd,char* write_buf,int write_size);

#endif
