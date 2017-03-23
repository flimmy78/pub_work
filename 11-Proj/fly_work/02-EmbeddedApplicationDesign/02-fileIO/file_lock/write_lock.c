/*******************************************************************
 *   > File Name: write_lock.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 23 Mar 2017 10:04:03 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "lock_file.c"

extern int lock_set(int fd, int type);

int main(int argc, char* argv[])
{
    int fd;

    /*打开文件*/
    if((fd = open("hello", O_RDWR)) < 0){
        perror("fail to open");return (-1);
    }

    /*给文件上写入锁*/
    lock_set(fd, F_WRLCK);
    getchar();//等待用户输入
    /*给文件解锁*/
    lock_set(fd, F_UNLCK);
    getchar();
    close(fd);

    return 0;
}
