/*******************************************************************
 *   > File Name: 02-fifo_read.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 02 Jan 2018 05:00:47 AM PST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define  MYFIFO     "./myfifo"

int main(int argc, char* argv[])
{
    char buf[256];
    int fd;
    int nread;

    /*判断有名管道是否存在，若尚未创建，则以相应的权限创建*/
    if(access(MYFIFO, F_OK) == -1){
        if(mkfifo(MYFIFO, 0666) < 0){
            perror("fail to mkfifo");
            exit(-1);
        }
    }

    /*以只读方式打开有名管道*/
    if((fd = open(MYFIFO, O_RDONLY)) < 0){
        perror("fail to open fifo");
        exit(-1);
    }

    while(1){
        memset(buf, 0, sizeof(buf));

        if((nread = read(fd, buf, 256)) > 0){
            printf("Read '%s' from FIFO\n", buf);
        }
    }

    close(fd);

    return 0;
}
