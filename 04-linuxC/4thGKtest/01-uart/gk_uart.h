#ifndef __UART__H__
#define __UART__H__

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <pthread.h>

#define UART_ERR_OPEN_FAIL      -1
#define UART_ERR_CONFIG_FAIL    -2
#define BUFFER_SIZE     128
#define HOST_COM_PORT   2
#define MAX_COM_NUM     3
#define GENERAL         1
#define USBTTY          0
#define COM_TYPE        1

/* 串口编号 */
typedef enum uart_id_
{
    UART_0 = 0, //串口0,ttySGK0
    UART_1,     //串口1,ttySGK1
    UART_2,     //串口2,ttySGK2
    UART_NUM
}UART_ID;

/* 串口配置参数 */
typedef struct
{
    int UartID;     //串口编号
    int BaudRate;   //波特率
    int DataBite;   //数据位
    int Parity;     //奇偶校验位
    int StopBite;   //停止位
}UART_CONFIG;


    /* 配置串口 */
int set_com_config(int fd, int baud_rate, int data_bit, char parity, int stop_bits);
    /* 打开串口设备 */
int open_port(int com_port);
    /* 打开并配置串口 */
int gk_open_com_port(UART_CONFIG uart_config);
    /* 关闭串口 */
int gk_close_com_port(int fd);
    /* 从串口中读数据 */
signed int gk_read_com_port(signed int fd, char* read_buf, int read_size);
    /* 往串口中写数据 */
signed int gk_write_com_port(signed int fd,char* write_buf, int write_size);

/*初始化一个线程属性，并设置线程栈的大小*/
int SetPthreadStackSize(pthread_attr_t attr, size_t stacksize);


#endif
