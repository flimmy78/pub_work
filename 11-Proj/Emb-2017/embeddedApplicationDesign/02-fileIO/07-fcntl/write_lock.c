/*******************************************************************
 *   > File Name: write_lock.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Nov 2017 11:45:20 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "lock_set.h"

int lock_set(int fd, int type);

int main(int argc, char* argv[])
{
    int fd;

    /*首先打开文件*/
    if((fd = open("hello", O_RDWR|O_CREAT)) < 0){
        perror("fail to open");
        return -1;
    }

    /*给文件上锁*/
    lock_set(fd, F_WRLCK);
    getchar();  //等待用户键盘输入

    /*给文件解锁*/
    lock_set(fd, F_UNLCK);
    getchar();
    close(fd);

    return 0;
}
