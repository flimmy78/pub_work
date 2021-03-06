/*******************************************************************
 *   > File Name: lock_file.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Mar 2017 10:49:54 PM CST
 ******************************************************************/
#if (0)
int fcntl(int fd, int cmd, ... /* arg */ );
int fcntl(int fd, int cmd, struct flock *lock);
l_whence: SEEK_SET,SEEK_CUR,SEEK_END;
l_type:F_RDLCK,F_WRLCK,F_UNLCK;
#endif

#include <stdio.h>
/*include for fcntl*/
#include <unistd.h>
#include <fcntl.h>

#include "mylock.h"

int lock_set(int fd, int type){
    struct flock old_lock, lock;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_type = type;
    lock.l_pid = -1;

    /* 判断文件是否可以上锁 */
    fcntl(fd, F_GETLK, &lock);
    if(lock.l_type != F_UNLCK){
        /*判断文件不能上锁的原因*/
        if(lock.l_type == F_RDLCK){
            /*该文件已有读取锁*/
            printf("Read lock already set by %d\n", lock.l_pid);
        }else if(lock.l_type == F_WRLCK){
            /*该文件已有写入锁*/
            printf("Write lock already set by %d\n", lock.l_pid);
        }
    }

    /* l_type可能已被F_GETLK修改过 */
    lock.l_type = type;
    /* 根据不同的type值进行阻塞式上锁或者解锁 */
    if((fcntl(fd, F_SETLKW, &lock)) < 0){
        printf("Lock failed :type = %d\n",lock.l_type);return (-1);
    }
    
    /* 上锁或者解锁后，判断文件被那个进程上锁 */
    switch(lock.l_type){
        case F_RDLCK:
            {
                printf("Read lock set by %d\n",getpid());
            }
            break;
        case F_WRLCK:
            {
                printf("Write lock set by %d\n",getpid());
            }
            break;
        case F_UNLCK:
            {
                printf("Release lock by %d\n",getpid());return 1;
            }
            break;
    }/* end of switch*/

    return 0;
}
