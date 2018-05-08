/*******************************************************************
 *   > File Name: 01-fifo_write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 02 Jan 2018 04:49:39 AM PST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define MYFIFO  "./myfifo"   /*有名管道文件名*/

int main(int argc, char* argv[])
{
    int fd;
    int nwrite;

    if(argc < 2){
        printf("Usage : ./fifo_write string\n");
        exit(-1);
    }

    /*以只写方式打开FIFO管道*/
    if((fd = mkfifo(MYFIFO, O_WRONLY)) < 0){
        perror("Fail to open fifo");
        exit(-1);
    }

    /*向管道中写入字符串*/
    if((nwrite = write(fd, argv[1], strlen(argv[1] + 1))) > 0){
        printf("Write '%s' to FIFO\n", argv[1]);
    }

    close(fd);

    return 0;
}
