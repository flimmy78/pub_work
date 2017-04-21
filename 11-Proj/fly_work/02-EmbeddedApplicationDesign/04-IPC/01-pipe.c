/*******************************************************************
 *   > File Name: 01-pipe.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 11:56:47 AM CST
 ******************************************************************/
/*头文件*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*宏定义*/
#define MAX_DATA_LEN    256
#define DELAY_TIME      1

int main(int argc, char* argv[])
{
    pid_t pid;

    int pipe_fd[2];
    char buf[MAX_DATA_LEN];

    const char data[] = "Pipe Test Program";
    int real_read, real_write;

    memset(buf, 0, sizeof(buf));
    if(pipe(pipe_fd) < 0){/*创建管道*/
        perror("fail to pipe");exit(-1);
    }

    if((pid = fork()) == 0){/*创建子进程*/
        /*子进程关闭写描述符，并通过使子进程暂停1s等待父进程关闭相应的读描述符*/
        close(pipe_fd[1]);
        sleep(DELAY_TIME);
        /*子进程读取管道内的内容*/
        if((real_read = read(pipe_fd[0] ,buf ,MAX_DATA_LEN)) > 0){
            printf("%d bytes read from the pipe is '%s'\n" ,real_read ,buf);
        }

        close(pipe_fd[0]);/*关闭子进程读描述符*/
        exit(0);
    }else if(pid > 0){
        /*父进程关闭文件描述符*/
        close(pipe_fd[0]);
        if((real_write = write(pipe_fd[1] ,data ,strlen(data))) != -1){
            printf("parent wrote %d bytes : '%s'\n",real_write, data);
        }

        close(pipe_fd[1]);/*关闭父进程写描述符*/
        waitpid(pid, NULL, 0);/*收集子进程退出信息*/
        exit(0);
    }

    return 0;
}
