/*******************************************************************
 *   > File Name: 06-create_send_fifo.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 05 Apr 2017 09:31:05 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*创建一个传送参数的FIFO*/
//@param(int):传入一个会话ID;
//@param(out):返回一个打开的文件描述符
int create_send_cgi(int session){
    int fd;
    int res;

    char cgi_fifo[20];
    sprintf(cgi_fifo, "/tmp/param_send%d", session);/*填充路径名*/

    if((res = access(cgi_fifo, F_OK)) != 0){        //检测文件是否存在
        if((res = mkfifo(cgi_fifo, 0666)) != 0){    //创建管道名
            fprintf(stderr, "Mkfifo %s err\n",cgi_fifo);return (-1);
        }
    }

    if((res = chmod(cgi_fifo, 0666)) != 0){         //改变文件权限
        fprintf(stderr, "chmod %s err\n", cgi_fifo);
    }

    if((fd = open(cgi_fifo, O_RDWR)) < 0){          //打开文件
        fprintf(stderr, "open %s err\n", cgi_fifo);return (-2);
    }

    return fd;
}

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2){
        printf("\tUsage : %s <param_send_num>\n",argv[0]);exit(EXIT_FAILURE);
    }

    int FILE_NUM;
    FILE_NUM = atoi(argv[1]);

    int ret;
    if((ret = create_send_cgi(FILE_NUM)) < 0){
        printf("Create_send_cgi err\n");exit(EXIT_FAILURE);
    }
    printf("create_send_cgi OK, res = %d\n",ret);

    return 0;
}
