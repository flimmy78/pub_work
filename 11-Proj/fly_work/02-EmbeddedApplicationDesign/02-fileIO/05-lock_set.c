/*******************************************************************
 *   > File Name: 05-lock_set.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 04:36:10 PM CST
 ******************************************************************/

#include <stdio.h>

int lock_set(int fd, int type)
{
    struct flock old_lock, lock;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_type = type;
    lock.l_pid = -1;

    /*判断文件是否上锁*/
    fcntl();
}

int main(int argc, char* argv[])
{
    return 0;
}
