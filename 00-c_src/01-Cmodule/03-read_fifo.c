/*******************************************************************
 *   > File Name: 03-read_fifo.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 03:57:15 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int read_fifo(int fd, void * buf, size_t count, int time_out_sec){
    int read_size = 0, nfds;
    fd_set fds;
    struct timeval tv;

    nfds = fd + 1;  
    
    tv.tv_sec = time_out_sec;   /*设置监控的时间*/
    tv.tv_usec = 0;

    memset(buf, 0, count);

    FD_ZERO(&fds);      /*清空文件描述符集合*/
    FD_SET(fd, &fds);   /*设置文件描述符集合*/
    /* 监控文件描述符的状态 */
    switch(select(nfds, &fds, NULL, NULL, &tv)){
        case 0:
            {
                return (-1);    /*Time Out*/
            }
            break;
        case (-1):
            {
                return (-2);    /*Error*/
            }
            break;
        default:
            {
                if(FD_ISSET(fd, &fds)){ /*fd 可读*/
                    if((read_size = read(fd, buf, count)) <= 0){
                        perror("read from fifo err");return (-3);
                    }
                }
            }
    }
    return read_size;/*返回读到的字节数*/
}


#define DEBUG_TEST
#ifdef DEBUG_TEST
int main(int argc, char* argv[])
{
    char BUF[128];
    int ret;

    ret = read_fifo(0, BUF, 128, 5);
    printf("ret = %d\n",ret);
    if(ret > 0){
        printf("read from stdin :%sEnd\n",BUF);
    }
    

    return 0;
}
#endif
