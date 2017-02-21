
/*******************************************************************
 *   > File Name: dvr_uart_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Feb 2017 05:19:43 PM CST
 ******************************************************************/

#include "dvr_uart.h"
#include "sd_file.h"
#include "obd_uart.h"



static void *uart_readPthread(void *param){
#if (0)
    if(pthread_detach(pthread_self()) != 0)/*设置线程的分离属性*/{
        printf("uart_readPthread  : pthread_detach err\n");return NULL;
    }
#endif

    /*获得文件描述符*/
    static int uart_fd = 0, file_fd = 0;
    uart_fd = ((P_FDS)param)->FD_0, file_fd = ((P_FDS)param)->FD_1;
    //printf("%s :start run uart_fd = %d\tfile_fd = %d\n",__func__,uart_fd,file_fd);
    
    unsigned int count_read = 0,count_write = 0;
    while(1){
        char RBUF[BUFSIZ];
        static int real_read_size = 0,real_write_size = 0;

        memset(RBUF, 0 , BUFSIZ);/*RBUF空间清零*/
        real_read_size = gk_read_com_port(uart_fd, RBUF, BUFSIZ);/*从串口获取数据*/
        if(real_read_size < 0){
            printf("read uart com port err\n");
        }
        else if(real_read_size > 0){
            count_read ++;
            printf("\n----Receive UART_data %d\n",count_read);
            if(count_read == (UINT_MAX - 1)){
                count_read = 0;
            }
        }
#if (1)/*打印接收到的字符*/
        int i = 0;
        for(i = 0; i < real_read_size; i++){
            printf(" %02X",RBUF[i]);
        }
#endif
        real_write_size = write(file_fd, RBUF, real_read_size);/*将数据写进文件*/
        if(real_write_size != real_read_size){
            perror("write RBUF to SD_FILE err");
        }
        else if(real_write_size > 0){
            count_write ++;
            printf("\n++++Write to SD_FILE %d\n",count_write);
            if(count_write == (UINT_MAX - 1)){
                count_write = 0;
            }
        }
    }    
    return NULL;
}

void uart_readService(void *param){
    pthread_t urs_pid;
    pthread_attr_t urs_attr;

    if(SetPthreadStackSize(&urs_attr, 250000) != 0){
        perror("SetPthreadStackSize err");
    }

    if(pthread_create(&urs_pid, &urs_attr, uart_readPthread, param) != 0){
        perror("pthread_create : uart_readPthread");
    }

    if((pthread_join(urs_pid, NULL)) != 0){
        perror("pthread_join urs_pid err");
    }
}

#if (1)
static void *uart_writePthread(void *param)
{
#if (0)
    if(pthread_detach(pthread_self()) != 0){
        return NULL;
    }
#endif
    
    /*获得文件描述符*/
    static int uart_fd ;
    uart_fd = ((P_FDS)param)->FD_0;
    int input_fd = STDIN_FILENO;/*标准输入*/

    while(1){
        char WBUF[BUFSIZ];
        static int real_read_size = 0, real_write_size = 0;

        memset(WBUF, 0 , BUFSIZ);
        while((real_read_size = read(input_fd,WBUF,BUFSIZ)) > 0){
#if (1)
            static int j;
            for(j = 0; j< real_read_size ; j++){
                printf("%c",WBUF[j]);
            }
            puts("");
#endif
            if((real_write_size = write(uart_fd, WBUF, real_read_size)) != real_read_size){
                fprintf(stdout,"Line:%d write err :%s\n",__LINE__,strerror(errno));
            }
        }
    }

    
    return NULL;
}

void uart_writeService(void *param){
    pthread_t uws_pid;
    pthread_attr_t uws_attr;

    if((SetPthreadStackSize(&uws_attr, 250000)) != 0){
        perror("SetPthreadStackSize");
    }

    if((pthread_create(&uws_pid, &uws_attr, uart_writePthread,param )) != 0){
        perror("pthread_create uart_writePthread err");
    }

    if((pthread_join(uws_pid, NULL)) != 0){
        perror("pthread_join uws_pid err");
    }
}

#endif

int main(int argc, char* argv[])
{
    /*1.初始化串口及文件*/
    int u_fd, f_fd;
    u_fd = uart_fd_init();/*串口*/
    f_fd = create_sd_file();/*文件*/

    FDS fds;
    P_FDS pfds = &fds;
    fds.FD_0 = u_fd ,fds.FD_1 = f_fd;

    printf("In main: uart_fd = %d\tfile_fd = %d\n",pfds->FD_0,pfds->FD_1);


    /*3.向串口写数据*/
    uart_writeService((void*)pfds);


    /*4.从串口读数据*/
    uart_readService((void*)pfds);

    /*5.关闭文件*/
    gk_close_com_port(u_fd);
    close_sd_file(f_fd);
    return 0;
}
