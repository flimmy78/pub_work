/*******************************************************************
 *   > File Name: dvr_uart_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Feb 2017 05:19:43 PM CST
 ******************************************************************/

#include "dvr_uart.h"
#include "sd_file.h"

int main(int argc, char* argv[])
{
    /*1.打开配置串口*/
    int ret,uart_fd;
    UART_CONFIG uart_cfg = {
        .UartID = UART_2,
        .BaudRate = 115200,
        .DataBite = 8,
        .Parity = 'N',
        .StopBite = 1
    };

    ret = gk_open_com_port(uart_cfg);
    if(ret < 0)
    {
        printf("gk_open_com_port err\n");
        return (-1);
    }
    else
    {
        uart_fd = ret;
        printf("gk_open_com_port OK\n");
    }

    /*2.新建文件*/
    char filepathname[SD_NAMEPATH_SIZE];
    if(get_file_path(filepathname, SD_NAMEPATH_SIZE) == NULL)
    {
        printf("get_file_path err\n");
        return (-1);
    }
    else
    {
        printf("filenamepath OK :%s\n",filepathname);
    }

    int file_fd;
    ret = open_sd_file(filepathname);
    if(ret < 0)
    {
        printf("open_sd_file %s err\n",filepathname);
        return (-1);
    }
    else
    {
        file_fd = ret;
        printf("open_sd_file %s ok fd is %d\n",filepathname,file_fd);
    }

    /*3.向串口写数据*/
    /*4.从串口读数据*/
    /*5.关闭文件*/
    gk_close_com_port(uart_fd);
    close_sd_file(file_sd);
    return 0;
}
