/*******************************************************************
 *   > File Name: 02-fifo_write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 01:21:42 PM CST
 ******************************************************************/
/*头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
/*宏定义*/
#define MYFIFO  "/tmp/myfifo"   /*有名管道文件名*/

int main(int argc, char* argv[])/*参数为即将写入的字符串*/
{
    int fd;
    int nwrite;

    if(argc < 2){/*判断传入参数*/
        printf("Usage : ./fifo_write string\n");exit(-1);
    }

    /*以只写方式打开FIFO管道*/
    if((fd = open(MYFIFO, O_WRONLY)) < 0){
        perror("fail to open fifo");exit(-1);
    }

    /*向管道中写入字符串*/
    if((nwrite = write(fd, argv[1], strlen(argv[1]) + 1)) > 0){
        printf("write '%s' to FIFO\n",argv[1]);
    }

    close(fd);


    return 0;
}
