/*******************************************************************
 *   > File Name: 99-pipe.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 19 Mar 2017 10:57:55 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

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

    /*创建进程*/
    if(pipe(pipe_fd) < 0){
        perror("fail to pipe");exit(-1);
    }

    /*创建进程*/
    if((pid = fork()) == 0){
        close(pipe_fd[1]);/*子进程关闭写描述符*/
        sleep(DELAY_TIME);
        /*子进程读取管道内容*/
        if((real_read = read(pipe_fd[0], buf, MAX_DATA_LEN)) > 0){
            printf("%d bytes read from the pipe is '%s' \n", real_read, buf);
        }
        close(pipe_fd[0]);/*子进程关闭读描述符*/
        exit(0);
    }else if(pid > 0){
        close(pipe_fd[0]);
        if((real_write = write(pipe_fd[1], data, strlen(data))) != -1){
            printf("parent wrote %d bytes : '%s'\n",real_write, data);
        }

        close(pipe_fd[1]);
        waitpid(pid, NULL, 0);
    }

    return 0;
}
