/*******************************************************************
 *   > File Name: fifo_write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 19 Mar 2017 11:32:00 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define MYFIFO  "/tmp/myfifo"

int main(int argc, char* argv[])
{
    int fd;
    int nwrite;

    if(argc < 2){
        printf("Usage : %s string \n",argv[0]);exit(-1);
    }

    /*以只写方式打开FIFO管道*/
    if((fd = open(MYFIFO, O_WRONLY)) < 0){
        perror("fail to open fifo");exit(-1);
    }

    /*向管道中写入字符串*/
    if((nwrite = write(fd, argv[1], strlen(argv[1]) + 1)) > 0){
        printf("Write '%s' to FIFO\n", argv[1]);
    }
    close(fd);

    return 0;
}
