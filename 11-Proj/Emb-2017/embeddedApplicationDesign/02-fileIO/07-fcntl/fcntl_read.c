/*******************************************************************
 *   > File Name: fcntl_read.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Nov 2017 12:25:57 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "lock_set.h"

int main(int argc, char* argv[])
{
    int fd;

    fd = open("Hello", O_RDWR|O_CREAT, 0644);
    if(fd < 0){
        printf("Open file error\n");
        exit(1);
    }

    /*给文件上读取锁*/
    lock_set(fd, F_RDLCK);
    getchar();

    /*给文件解锁*/
    lock_set(fd, FUNLCK);
    getchar();
    close(fd);

    return 0;
}
