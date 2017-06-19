/*******************************************************************
 *   > File Name: 05-flock.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 10:04:26 2017
 ******************************************************************/
#if (0)
int flock(int fd, int operation);   //锁定文件或解除锁定
//依参数 operation 所指定的方式对参数 fd 所指的文件做
//各种锁定或解除锁定的动作。此函数只能锁定整个文件，无法锁定
//文件的某一区域。
//参数 operation 有下列四种情况：
LOCK_SH 建立共享锁定。多个进程可同时对同一个文件作共享锁定。
LOCK_EX 建立互斥锁定。一个文件同时只有一个互斥锁定。
LOCK_UN 解除文件锁定状态。
LOCK_NB 无法建立锁定时，此操作可不被阻断，马上返回进程。
//通常与 LOCK_SH 或 LOCK_EX 做 OR（|）组合。
//单一文件无法同时建立共享锁定和互斥锁定，而当使用 dup（）或
//fork（）时文件描述词不会继承此种锁定。
//返回 0 表示成功，若有错误则返回-1，错误代码存于 errno。
#endif

#include <stdio.h>
#include <sys/file.h>

int main(int argc, char* argv[])
{
    return 0;
}
