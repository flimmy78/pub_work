/*******************************************************************
 *   > File Name: 00-pipe.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 29 Dec 2017 07:29:13 AM PST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
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

    memset(buf, 0, sizeof(buf));/*初始化buf*/

    if(pipe(pipe_fd) < 0){
        /*创建管道*/
        perror("fail to pipe");
        exit(1);
    }

    if((pid = fork()) == 0){    /*子进程*/
        close(pipe_fd[1]);/*关闭写管道*/
        sleep(DELAY_TIME);

        if((real_read = read(pipe_fd[0], buf, MAX_DATA_LEN)) > 0){
            printf("%d bytes read from the pipe is '%s'\n",real_read, buf);
        }

        close(pipe_fd[0]);
        exit(0);
    }else if(pid > 0){      /*父进程*/
        close(pipe_fd[0]);  /*关闭读管道*/

        if((real_write = write(pipe_fd[1], data, strlen(data))) != -1){
            printf("Parent wrote %d bytes : '%s'\n", real_write, data);
        }

        close(pipe_fd[1]);

        waitpid(pid, NULL, 0);
    }

    return 0;
}
