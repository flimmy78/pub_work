/*******************************************************************
 *   > File Name: read_lock.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 23 Mar 2017 10:14:31 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "lock_file.c"

extern int lock_set(int fd, int type);

int main(int argc, char* argv[])
{
    int fd;

    fd = open("hello", O_RDWR | O_CREAT, 0644);
    if( fd < 0){
        printf("Open file error\n");exit(1);
    }

    /*给文件上锁*/
    lock_set(fd, F_RDLCK);
    getchar();
    /*给文件解锁*/
    lock_set(fd, F_UNLCK);
    getchar();
    close(fd);

    return 0;
}
