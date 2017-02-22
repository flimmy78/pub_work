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

#if (1)
static void *uart_servicePthread(void *param){
    static int uart_fd = 0, file_fd = 0 , in_fd;
    uart_fd = ((P_FDS)param)->FD_0, file_fd = ((P_FDS)param)->FD_1, in_fd = ((P_FDS)param)->FD_2;

    printf("uart_fd = %d, file_fd = %d, in_fd = %d\n",uart_fd, file_fd, in_fd);
    while(1){
        printf("this is test\n");
        sleep(1);
    }
    
    

    return NULL;
}

void uart_service(void *param){
    pthread_t u_pid;
    pthread_attr_t u_attr;

    if(SetPthreadStackSize(&u_attr, 250000) != 0){
        perror("SetPthreadStackSize err");
    }

    if(pthread_create(&u_pid, &u_attr, uart_servicePthread, param) != 0){
        perror("pthread_create : uart_readPthread");
    }

    if(pthread_join(u_pid, NULL) != 0){
        perror("pthread_join u_id err");
    }
}


#endif

int main(int argc, char* argv[])
{
    int u_fd, f_fd, i_fd;
    u_fd = uart_fd_init(),f_fd = create_sd_file(), i_fd = STDIN_FILENO;

    FDS fds;
    P_FDS pfds = &fds;
    fds.FD_0 = u_fd, fds.FD_1 = f_fd, fds.FD_2 = i_fd;

    printf("串口：%d ,文件：%d ，输入：%d\n",pfds->FD_0, pfds->FD_1, pfds->FD_2);
    uart_service((void*)pfds);


    return 0;
}
