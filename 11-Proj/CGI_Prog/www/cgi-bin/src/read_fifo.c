/*******************************************************************
 *  *   > File Name: read_fifo.c
 *   *   > Author: fly
 *    *   > Mail: XXXXXXXX@icode.com
 *     *   > Create Time: Mon 20 Mar 2017 01:07:17 AM CST
 *      ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define MYFIFO "/tmp/FIFOTEST"

int main(int argc, char* argv[])
{
    char buf[256];
    int fd;

    if(access(MYFIFO, F_OK) == -1){
        if(mkfifo(MYFIFO, 0666) < 0){
            perror("fail to mkfifo");exit(-1);
        }
    }

    if((fd = open(MYFIFO, O_RDONLY)) < 0){
        perror("fail to open fifo");exit(-1);
    }

    int nread;
    while(1){
        memset(buf, 0, sizeof(buf));
        if((nread = read(fd, buf, 256)) > 0){
            buf[strlen(buf) - 1] = '\0';
            printf("Read '%s' from FIFO\n",buf);
        }
    }
    close(fd);

    return 0;
}

