/*******************************************************************
 *   > File Name: 04-fcntl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 09:51:05 2017
 ******************************************************************/
#if (0)
//文件描述词操作 
int fcntl(int fd, int cmd, .../* arg */);
int fcntl(int fd, int cmd);
int fcntl(int fd, int cmd, long arg);
int fcntl(int fd, int cmd, struct flock *lock);
//fcntl（）用来操作文件描述词的一些特性。参数 fd 代表欲设置的文
//件描述词，参数 cmd 代表欲操作的指令，有以下几种情况：
F_DUPFD 用来查找大于或等于参数 arg 的最小且仍未使用的文
件描述词，并且复制参数 fd 的文件描述词。执行成功则返
回新复制的文件描述词。请参考 dup2（）。
F_GETFD 取得 close-on-exec 旗标。若此旗标的 FD_CLOEXEC
位为 0，代表在调用 exec（）相关函数时文件将不会关闭。
F_SETFD 设 置 close-on-exec 旗 标 。 该 旗 标 以 参 数 arg 的
FD_CLOEXEC 位决定。
F_GETFL 取得文件描述词状态旗标，此旗标为 open（）的参数flags。
F_SETFL 设置文件描述词状态旗标，参数 arg 为新旗标，但只允
许 O_APPEND、O_NONBLOCK 和 O_ASYNC 位的改变，他位的改变将不受影响。
F_GETLK 取得文件锁定的状态
F_SETLK 设置文件锁定的状态。此时 flcok 结构的 l_type 值必
须是 F_RDLCK、F_WRLCK 或 F_UNLCK。如果无法建立
锁定，则返回-1，错误代码为 EACCES 或 EAGAIN。
F_SETLKW F_SETLK 作用相同，但是无法建立锁定时，此调用
会一直等到锁定动作成功为止。若在等待锁定的过程中被
信号中断时，会立即返回-1，错误代码为 EINTR。参数 lock
指针为 flock 结构指针，定义如下：
struct flcok
{
    short int l_type; /* 锁定的状态*/
    short int l_whence;/*决定 l_start 位置*/
    off_t l_start; /*锁定区域的开头位置*/
    off_t l_len; /*锁定区域的大小*/
    pid_t l_pid; /*锁定动作的进程*/
};
//l_type 有三种状态：
F_RDLCK 建立一个供读取用的锁定
F_WRLCK 建立一个供写入用的锁定
F_UNLCK 删除之前建立的锁定返回值
l_whence 也有三种方式：
SEEK_SET 以文件开头为锁定的起始位置。
SEEK_CUR 以目前文件读写位置为锁定的起始位置
SEEK_END 以文件结尾为锁定的起始位置。
成功则返回 0，若有错误则返回-1，错误原因存于 errno
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    return 0;
}
