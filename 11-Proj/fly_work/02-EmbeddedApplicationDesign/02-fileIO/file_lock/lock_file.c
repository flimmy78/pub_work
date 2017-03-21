/*******************************************************************
 *   > File Name: lock_file.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Mar 2017 10:49:54 PM CST
 ******************************************************************/
#if (0)
#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
#endif

int lock_set(int fd, int type){
    struct flock old_lock, lock;
    lock.l_whence = SEEK_SET;
    lock.l_stat = 0;
    lock.l_len = 0;
    lock.l_type = type;
    lock.l_pid = -1;

    /* 判断文件是否可以上锁 */
    fcntl(fd, F_GETLK, &lock);
}
