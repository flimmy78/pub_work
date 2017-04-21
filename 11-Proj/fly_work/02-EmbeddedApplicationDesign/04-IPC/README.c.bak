4.1-Linux下进程间通讯概述：
    4.1.1无名管道（pipe）和有名管道（fifo）
    4.1.2信号（signal）
    4.1.3消息队列(massage quence)
    4.1.4共享内存（sharedmemory）
    4.1.5信号量（semaphore）
    4.1.6套接字（socket）

4.2-无名管道（pipe）
    #include <unistd.h>
    int pipe(int fd[]);
    函数传入值：包含两个元素的整型数组，存放管道对应的文件描述符；
    函数返回值：成功，返回0；出错，返回-1；

4.2.3-有名管道（FIFO）
    #include <sys/types.h>
    #include <sys/stat.h>
    int mkfifo(const char*filename, mode_t mode);
    参数1：filename(要创建的管道)；
    参数2：mode（管道的访问权限）；
    函数的返回值：成功，返回0；出错，返回-1；

    FIFO的出错信息：
    EACCESS：参数filename所指定的目录路径无可执行的权限；
    EEXIST：参数filename所指定的文件已经存在；
    ENAMETOOLONG：参数filename的路径名称太长；
    ENOENT：参数filename包含的文件不存在；
    ENOSPC：文件系统的剩余空间不足；
    ENOTDIR：参数filename路径中的目录存在但却非真正的目录；
    EROFS：参数filename指定的文件存在于只读的文件系统中；

4.3-信号通讯
    进程通过3种方式来响应一个信号；
    （1）、忽略信号（不做任何处理，SIGKILL、SIGSTOP-不可忽略）；
    （2）、捕捉信号（定义信号处理函数）；
    （3）、执行默认操作：
    SIGHUP：
    SIGINT：
    SIGQUIT：
    SIGILL:
    SIGFPE:
    SIGKILL:
    SIGALARM:
    SIGSTOP:
    SIGTSTP:
    SIGCHLP:
    信号相关的函数：
    发送信号的函数：kill（），raise（）；
    设置信号的函数：signal（），sigaction（）；
    其他函数：alarm（），pause（）；

4.3.2-信号的发送与设置
    1.信号发送：kill（），raise（）；
#include <signal.h>
#include <sys/types.h>

int kill(pid_t pid, int sig);
pid: 整数：发送信号给进程号为pid的进程；
    0：信号被发送到所有和当前进程在同一个进程组的进程；
    -1：信号发送给所有的进程表中的进程（除了进程号最大的进程外）；
    <-1:信号发送给进程组号为-pid的每一个进程；
sig：信号内型；
函数返回值：成功，返回0；失败，返回-1；
/*--------------------------------------------------------------*/
#include <signal.h>
#include <sys/types.h>

int raise(int sig);
函数传入值：sig（信号类型）；
函数返回值：成功返回0，失败返回-1；
    2.定时器信号：alarm（）、pause（）；
    3.信号的设置：signal（）、sigaction（）;

4.4-信号量
    {
        /*设R为某种资源，S为保护资源R的信号量*/
        INIT_VAL(s);    /*对信号量S进行初始化*/
        非临界区；
        P(S);           /*进行P操作*/
        临界区（访问资源R）；/*只有有限个（通常只有一个）进程被允许进入该区*/
        V(S);           /*进行V操作*/
        非临界区；
    }
    
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semget(key_t key, int nsems, int semflg);
key:信号量的键值，多个进程可以通过它访问同一个信号量，其中有个特殊值IPC_PRIVATE.
它用于创建当前进程的私有信号量。
nsems：需要创建的信号量数目，通常取值为1；


