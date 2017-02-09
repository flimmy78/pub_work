/*******************************************************************
 *   > File Name: 06-write_lock.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 10:56:47 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int lock_set(int fd, int type);

int main(int argc, char* argv[])
{
    int fd;

    /*首先打开文件*/
    if((fd = open("hello", O_RDWR)) < 0)
    {
        perror("fail to open");
        return (-1);
    }

    /*给文件上锁*/
    lock_set(fd, F_WRLCK);
    getchar();  //等待用户输入
    /*给文件解锁*/
    lock_set(fd, F_UNLCK);
    getchar();
    close(fd);

    return 0;
}
