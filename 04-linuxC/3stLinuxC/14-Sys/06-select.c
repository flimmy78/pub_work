/*******************************************************************
 *   > File Name: 06-select.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 05:27:25 PM CST
 ******************************************************************/
#if (0)
/*IO多工机制*/
int select(int nfds, fd_set *readfds, fd_set *writefds,
        fd_set *exceptfds, struct timeval *timeout);
//select（）用来等待文件描述词状态的改变。参数 n 代表最大的文件
//描述词加 1，参数 readfds、writefds 和 exceptfds 称为描述词组，是
//用来回传该描述词的读，写或例外的状况
//如果参数 timeout 设为 NULL 则表示 select（）没有 timeout。

void FD_CLR(int fd, fd_set *set);/*清除描述词组set中相关fd的位*/
int  FD_ISSET(int fd, fd_set *set);/*测试描述词组set中相关fd的位是否为真*/
void FD_SET(int fd, fd_set *set);/*用来设置描述词组set中相关fd的位*/
void FD_ZERO(fd_set *set);/*用来清除描述词组set的全部位*/

//执行成功则返回文件描述词状态已改变的个数，如果返回 0 代表在
//描述词状态改变前已超过 timeout 时间，当有错误发生时则返回-1，
//错误原因存于 errno，此时参数 readfds， writefds， exceptfds 和 timeout
//的值变成不可预测。
struct timeval {
    long    tv_sec;         /* seconds */
    long    tv_usec;        /* microseconds */
};

/*代码片段*/
fs_set readset；
FD_ZERO(&readset);
FD_SET(fd,&readset);
select(fd+1,&readset,NULL,NULL,NULL);
if(FD_ISSET(fd,readset)){
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    FD_ZERO(&rfds);
    FD_SET(0,&rfds);

    retval = select(1, &rfds, NULL, NULL, &tv);

    if(retval == -1){/*出错*/
        perror("select()");
    }else if(retval == 1){/*有数据*/
        printf("Data is avaliable now\n");
        /*FD_ISSET(0, &rfds); will be true.*/
    }else if(retval == 0){/*超时*/
        printf("No data within five seconds.\n");
    }

    return 0;
}
