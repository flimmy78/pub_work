/*******************************************************************
 *   > File Name: dvr_uart_t3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 22 Feb 2017 03:44:05 PM CST
 ******************************************************************/

#include <stdio.h>
#include "dvr_uart.h"
#include "sd_file.h"
#include "obd_uart.h"

static void *uart_servicePthread(void *param){
    static int uart_fd = -1, file_fd = -1 , in_fd = -1;
    uart_fd = ((P_FDS)param)->FD_0, file_fd = ((P_FDS)param)->FD_1, in_fd = ((P_FDS)param)->FD_2;

    //printf("uart_fd = %d, file_fd = %d, in_fd = %d\n",uart_fd, file_fd, in_fd);
    
    int maxfd = file_fd,ret;
    fd_set rd_set;
    FD_ZERO(&rd_set);

    unsigned int count_read = 0, count_write_uart = 0, count_write_sd = 0;
    while(1){
        FD_SET(in_fd, &rd_set);
        FD_SET(uart_fd, &rd_set);
        FD_SET(file_fd, &rd_set);

        char RBUF[BUFSIZ], WBUF[BUFSIZ];
        static int real_read_size = 0, real_write_size = 0;

        ret = select(maxfd + 1, &rd_set, NULL, NULL, NULL);
        if(ret > 0){/*有数据*/
            if(FD_ISSET(uart_fd, &rd_set)){/*串口有数据可读*/
                //printf("\nuart_fd has data");
                //sleep(1);

                memset(RBUF, 0, BUFSIZ);
                real_read_size = gk_read_com_port(uart_fd, RBUF, BUFSIZ);
                if(real_read_size < 0){
                    perror("read uart com port err\n");
                }else if(real_read_size > 0){
                    count_read++;
                    printf("\n----Receive %d bytes UART_data  %d OK\n",real_read_size, count_read);
                    if(count_read == (UINT_MAX - 1)){
                        count_read = 0;
                    }
                }
#if (1)/*打印通过串口收到的数据*/
                static int i;
                for(i = 0; i < real_read_size; i++){
#if (1)
                    printf(" %02X",RBUF[i]);
#else 
                    printf("%c",RBUF[i]);
#endif
                }
#endif
                /*将收到的数据进行处理成通用格式*/
                /*根据协议分析信息*/
                /*将数据写入到文件*/
                real_write_size = write(file_fd, RBUF, real_read_size);
                if(real_write_size != real_read_size){
                    perror("write RBUF to SD_file err");
                }else if(real_write_size > 0){
                    count_write_sd ++;
                    printf("\n----Write %d bytes to SD_file %d OK\n",real_write_size, count_write_sd);
                    if(count_write_sd == (UINT_MAX - 1)){
                        count_write_sd = 0;
                    }
                }


            }else if(FD_ISSET(in_fd,&rd_set)){/*有数据输入*/
                //printf("input has data\n");
                /*根据读到的信息反馈信息给发送方*/
                
                /*将输入的字符放入缓冲区WBUF*/
                memset(WBUF, 0, BUFSIZ);/*清空WBUF*/
                if(fgets(WBUF,BUFSIZ - 1,stdin) == NULL){
                    perror("read stdin err");
                }
                real_read_size = strlen(WBUF) - 1;
                WBUF[real_read_size] = '\0';
                printf("\nInput  %d char : %s\n",real_read_size, WBUF);
                
                /*将缓冲区WBUF的字符写入串口设备*/
                real_write_size = write(uart_fd, WBUF, real_read_size);
                if(real_write_size != real_read_size){
                    perror("write WBUF to uart_fd err");
                }else if(real_write_size > 0){
                    count_write_uart ++;
                    printf("----Write to uart_fd %d OK\n",count_write_uart);
                    if(count_write_uart ==(UINT_MAX - 1)){
                        count_write_uart = 0;
                    }
                }

            }
#if (0)
            else if(FD_ISSET(file_fd,&rd_set)){
                printf("file_fd is activity\n"); 
                sleep(1);
            }
#endif
        
        }else if(ret == 0){/*超时*/
            printf("No data within time.\n");
        }else if(ret < 0){/*出错*/
            printf("Data is available now.\n");
        }
    }
    
    return NULL;
}

void uart_service(void *param){
    pthread_t u_pid;/*定义一个线程ID*/
    pthread_attr_t u_attr;/*定义一个线程属性*/

    /*设置线程栈的大小*/
    if(SetPthreadStackSize(&u_attr, 250000) != 0){
        perror("SetPthreadStackSize err");
    }

    /*创建线程*/
    if(pthread_create(&u_pid, &u_attr, uart_servicePthread, param) != 0){
        perror("pthread_create : uart_readPthread");
    }

    /*回收线程*/
    if(pthread_join(u_pid, NULL) != 0){
        perror("pthread_join u_id err");
    }
}


int main(int argc, char* argv[])
{
    /*定义串口、文本、输入文件描述符并初始化*/
    int u_fd, f_fd, i_fd;
    u_fd = uart_fd_init(),f_fd = create_sd_file(), i_fd = STDIN_FILENO;

    /*定义一个文件句柄集合，并初始化*/
    FDS fds;
    P_FDS pfds = &fds;
    fds.FD_0 = u_fd, fds.FD_1 = f_fd, fds.FD_2 = i_fd;

    printf("串口：%d ,文件：%d ，输入：%d\n",pfds->FD_0, pfds->FD_1, pfds->FD_2);

    /*串口服务线程函数*/
    uart_service((void*)pfds);


    return 0;
}
