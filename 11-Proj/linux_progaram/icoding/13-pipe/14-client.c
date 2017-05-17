/*******************************************************************
 *   > File Name: 14-client.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 17 May 2017 11:08:21 AM CST
 ******************************************************************/

#include <stdio.h>
#include "client.h"
#include <ctype.h>

void debug(void);

int main(int argc, char* argv[])
{
    int server_fifo_fd, client_fifo_fd;
    struct data_to_pass_st my_data;
    int times_to_send;
    char client_fifo[256];

    debug();
    /*打开服务端管道文件描述符*/
    server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
    if(server_fifo_fd == -1){
        fprintf(stderr, "open server error\n");exit(EXIT_FAILURE);
    }

    /*获取客户端管道文件路径名*/
    my_data.client_pid = getpid();
    sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);
    
    /*创建管道*/
    if(mkfifo(client_fifo , 0777) == -1){
        fprintf(stderr, "can't make %s\n", client_fifo);exit(EXIT_FAILURE);
    }

    for(times_to_send = 0; times_to_send < 5; times_to_send ++){
        sprintf(my_data.some_data, "Hello from %d", my_data.client_pid);
        printf("%d send %s, ", my_data.client_pid, my_data.some_data);
        /*向服务器管道写信息*/
        write(server_fifo_fd, &my_data, sizeof(my_data));
    
        /*打开客户端管道*/
        client_fifo_fd = open(client_fifo, O_RDONLY);
        if(client_fifo_fd != -1){
            /*读管道*/
            if(read(client_fifo_fd, &my_data, sizeof(my_data)) > 0){
                printf("received : %s\n", my_data.some_data);
            }
            close(client_fifo_fd);
        }
    }
    
    close(server_fifo_fd);
    unlink(client_fifo);
    exit(EXIT_SUCCESS);
}

void debug(void){
    printf("[%s] (%s) <%d>\n", __FILE__, __func__, __LINE__);
}
