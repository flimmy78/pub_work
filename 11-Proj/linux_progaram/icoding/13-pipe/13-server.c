/*******************************************************************
 *   > File Name: 13-server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 17 May 2017 10:20:47 AM CST
 ******************************************************************/

#include <stdio.h>
#include "client.h"
#include <ctype.h>

int debug(void);

int main(int argc, char* argv[])
{
    int server_fifo_fd, client_fifo_fd;
    struct data_to_pass_st my_data;
    int read_res;
    char client_fifo[256];
    char *tmp_char_ptr;
    debug();
    
    /*创建并打开管道文件描述符*/
    mkfifo(SERVER_FIFO_NAME, 0777);
    server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY);
    if(server_fifo_fd == -1){
        fprintf(stderr, "Server fifo failure\n");exit(EXIT_FAILURE);
    }
    sleep(1);
    debug();

    do{
        read_res = read(server_fifo_fd, &my_data, sizeof(my_data));/*读取管道信息*/
        debug();
        if(read_res > 0){
            tmp_char_ptr = my_data.some_data;
            while(*tmp_char_ptr){
                *tmp_char_ptr = toupper(*tmp_char_ptr);
                tmp_char_ptr ++;
            }
            sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);

            client_fifo_fd = open(client_fifo, O_WRONLY);
            if(client_fifo_fd != -1){
                write(client_fifo_fd, &my_data, sizeof(my_data));
                close(client_fifo_fd);
            }
            debug();
        }
    }while(read_res > 0);

    close(server_fifo_fd);
    unlink(SERVER_FIFO_NAME);

    exit(EXIT_SUCCESS);
}

int debug(void){
    printf("[%s] (%s) <%d>\n",__FILE__, __func__, __LINE__);
    return 0;
}
