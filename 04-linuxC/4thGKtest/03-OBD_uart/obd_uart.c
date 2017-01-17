/*******************************************************************
 *   > File Name: OBD_uart.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 11 Jan 2017 02:02:47 PM CST
 ******************************************************************/

#include "OBD_uart.h"
#include "sd_file.h"
#include "dvr_uart.h"

#define DEBUG_OBD_UART

int g_main_run = 1;

int GK_SetPthreadStackSize(pthread_attr_t* attr, int stacksize)
{
    if((pthread_attr_init(attr)) != 0) /*初始化一个线程属性对象*/
    {
        return (-1);
    }
    if((pthread_attr_setstacksize(attr,stacksize)) != 0)
    {                           /*设置线程栈的大小*/
        return (-1);
    }
    return 0;
}

void* Uart_ReadPthread(void* arg)
{
    if((pthread_detach(pthread_self())) != 0)   /*设置线程的分离属性*/
    {
        return NULL;
    }

    FILE_FD FDS = (FILE_FD)arg;   /*获得文件描述符集合*/
    int R_uart_fd = FDS.uart_fd;   /*设备文件*/
    int R_sd_fd = FDS.sd_fd;       /*SD卡文件*/
    char RBUF[BUFSIZ];
    int real_read_size = 0, real_write_size = 0, count_read = 0, count_write = 0;

    while(g_main_run)
    {
        memset(RBUF, 0, BUFSIZ);
        real_read_size = gk_read_com_port(R_uart_fd, RBUF,BUFSIZ); /*读设备*/
        if(real_read_size < 0)  /*读取异常*/
        {
            printf("%s (%d) [%s] read uart port err\n ",__FILE__,__LINE__,__func__);
        }else if(real_read_size > 0)    /*读到数据*/
        {
            count_read++;
            printf("\n--------Receive UART_data %d\n",count_read);
            while(count_read = (UINT_MAX - 1))
            {
                count_read = 0;
            }
        }
#ifdef PRINT_UART
        int i = 0;
        for(i = 0; i < real_read_size; i++)
        {
            printf(" 0x%02X",RBUF[i]);
        }
#endif
        /*将缓冲BUF中的数据写入文件*/
        real_write_size = write(R_sd_fd, RBUF, real_read_size);
        if(real_write_size != real_read_size)
        {
            perror("Write RBUF to sd_fd err");
        }else if(real_write_size > 0)
        {
            count_write ++;
            printf("\n--------Write to sd_file %d\n",count_write);
            while(count_write = (UINT_MAX - 1))
            {
                count_write = 0;
            }
        }

        fsync(R_sd_fd);
        fflush(NULL);
    }

    gk_close_com_port(R_uart_fd); /*关闭文件*/
    close_sd_file(R_sd_fd);
    
    pthrea_exit(NULL);
}

void* Uart_WritePthread(void* arg)
{
    if((pthread_detach(pthread_self())) != 0)   /*设置线程的分离属性*/
    {
        return NULL;
    }
    
    FILE_FD FDS = (FILE_FD)arg;
    int W_uart_fd = FDS.uart_fd;
    char T_str[] = "<@1234567890aBcDeFgHiJkLmNoPqRsTuVwXyZ#>";
    int ret;
    ret = write(W_uart_fd, T_str,sizeof T_str);
    if(ret != sizeof(T_str))
    {
        printf("Write data err\n");
    }
    else
    {
        printf("Write data OK\n");
    }
    pthread_exit(NULL);
}

int Uart_StartServicce(void)
{
    /*1.打开配置串口*/
    FILE_FD rfds,wfds;
    UART_CONFIG uart_cfg = {
        .UartID = UART_2,
        .BaudRate = 115200,
        .DateBite = 8,
        .Parity = 'N',
        .StopBite = 1
    };

    if((rfds.uart_fd = gk_open_com_port(uart_cfg)) < 0)
    {
        printf("gk_open_com_port err\n");
        return (-1);
    }
    else
    {
        printf("gk_open_com_port OK\n");
        wfds.uart_fd = rfds.uart_fd;
    }
    
    /*2.新建文件*/
    char pathname[SD_NAMEPATH_SIZE];
    get_file_path(pathname, SD_NAMEPATH_SIZE);
    rfds.sd_fd = open_sd_file(pathname);
    wfds.other_fd = 0;

    /*3.创建读、写线程*/
    int pret = (-1);
    pthread_t pid_rd, pid_wr;
    pthread_attr_t attr;

    GK_SetPthreadStackSize(&attr, 500000);/*设置线程栈*/
    pret = pthread_create(&pid_rd, &attr, Uart_ReadPthread, (void*)rfds);
    if(pret != 0)
    {
        printf("Create Uart_ReadPthread err\n");
        return (-1);
    }
    pret = pthread_create(&pid_wr, &attr, Uart_WritePthread, (void*)wfds);
    if(pret != 0)
    {
        printf("Create Uart_WritePthread err\n");
        return (-1);
    }
    return 0;
}

int main(void)
{
    Uart_StartService();
    return 0;
}
