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
    /*1.配置打开串口*/
    int ret,uart_fd;
    uart_fd = uart_fd_init();

    /*2.新建文件*/
    int file_fd;
    file_fd = create_sd_file();

    /*3.向串口写数据*/
    char Wstr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    int real_write_size;
    real_write_size = gk_write_com_port(uart_fd,Wstr,27);
    if(real_write_size != 27)
    {
        printf("Write data err\n");
    }
    else
    {
        printf("Write data ok\n");
    }

    /*4.从串口读数据*/
    unsigned int count_read = 0, count_write = 0;
    while(1)
    {
        char RBUF[BUFSIZ];
        int real_read_size = 0;

        memset(RBUF, 0, BUFSIZ);
        real_read_size = gk_read_com_port(uart_fd, RBUF, BUFSIZ);
        if(real_read_size < 0)
        {
            printf("read uart com port err\n");
        }
        else if(real_read_size > 0)
        {
            count_read ++;
            printf("\n------Receive UART_data %d\n",count_read);
            if(count_read == (UINT_MAX - 1))
            {
                count_read = 0;
            }
        }
#if (1)
        int i = 0;
        for(i = 0; i < real_read_size; i++)
        {
            printf(" 0x%02X",RBUF[i]);
        }
#endif
        /*写入之前检查文件是否有错误*/
        if(ferror(fdopen(file_fd,"r+")))
        /*6.将读到的数据写入SD卡*/
        ret = write(file_fd, RBUF, real_read_size);
        if(ret != real_read_size)
        {
            perror("write RBUF to SD_FILE err");
        }
        else if(ret > 0)
        {
            count_write ++;
            printf("\n++++++Write to SD_FILE %d\n",count_write);
            if(count_write == (UINT_MAX - 1))
            {
                count_write = 0;
            }
        }
        
        fsync(file_fd);
        fflush(NULL);
    }

    /*5.关闭文件*/
    gk_close_com_port(uart_fd);
    close_sd_file(file_fd);
    return 0;
}
