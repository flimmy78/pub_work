/*******************************************************************
 *   > File Name: 13-server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 16 May 2017 02:52:53 PM CST
 ******************************************************************/

#include <stdio.h>
#include "client.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
    int server_fifo_fd, client_fifo_fd;
    struct data_to_pass_st my_data;
    int read_res;
    char client_fifo[256];
    char *tmp_char_ptr;

    /*以0777模式，创建管道*/
    mkfifo(SERVER_FIFO_NAME, 0777);
    /*打开管道文件描述符*/
    server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY);
    if(server_fifo_fd == -1){
        fprintf(stderr, "Server fifo failure\n");exit(EXIT_FAILURE);
    }

    sleep(10);

    do{
        /*读管道*/
        read_res = read(server_fifo_fd, &my_data, sizeof(my_data));
        if(read_res > 0){
            tmp_char_ptr = my_data.some_data;/*解析，获得字符串*/
            
            /*小写转大写*/
            while(*tmp_char_ptr){
                *tmp_char_ptr = toupper(*tmp_char_ptr);
                tmp_char_ptr ++;
            }

            /*获取客户端管道路径名*/
            sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);
            /*以可写模式打开文件描述符*/
            client_fifo_fd = open(client_fifo, O_WRONLY);
            if(client_fifo_fd != -1){
                write(client_fifo_fd, &my_data, sizeof(my_data));
                close(client_fifo_fd);
            }
        }
    }while(read_res > 0);

    close(server_fifo_fd);
    unlink(SERVER_FIFO_NAME);

    exit(EXIT_SUCCESS);
}
