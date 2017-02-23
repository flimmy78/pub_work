/*******************************************************************
 *   > File Name: 07-fcntl_read.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 11:11:30 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "lock_set.c"

int main(int argc, char* argv[])
{
    int fd;
    fd = open("hello", O_RDWR| O_CREAT, 0644);
    if(fd < 0){
        printf("Open file error\n");exit(1);
    }

    /*给文件上锁*/
    lock_set(fd, F_RDLCK);
    getchar();
    /*给文件解锁*/
    lock_set(fd, F_UNLCK);
    getchar();
    close(fd);
    exit(0);

    return 0;
}
