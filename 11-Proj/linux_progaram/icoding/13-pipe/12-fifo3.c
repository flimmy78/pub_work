/*******************************************************************
 *   > File Name: 12-fifo3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 16 May 2017 11:05:32 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME       "/tmp/my_fifo"  /*管道名称*/
#define BUFFER_SIZE     PIPE_BUF        /*BUF大小*/

int main(int argc, char* argv[])
{
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read = 0;

    memset(buffer, '\0', sizeof(buffer));
    
    printf("Process %d opening FIFO O_RDONLY\n", getpid()); /*打印当前进程ID*/
    pipe_fd = open(FIFO_NAME, open_mode);   /*以可读方式打开管道文件*/
    printf("Process %d result %d\n", getpid(), pipe_fd);    /*打印PID及管道文件描述符*/
    
    /*管道有数据，则读出，并统计字节数；否则，异常退出*/
    if(pipe_fd != -1){
        do{
            res = read(pipe_fd, buffer, BUFFER_SIZE);   /*read the buffer from pipe_fd*/
            bytes_read += res;
        }while(res > 0);
        (void)close(pipe_fd);
    }else{
        exit(EXIT_FAILURE);
    }

    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}
