/*******************************************************************
 *   > File Name: 03-fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Feb 2017 01:49:03 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    if((pid = fork()) < 0){/*出错*/
        perror("fork");
        exit(1);/*退出当前进程*/
    }else if(pid == 0){/*子进程*/
        printf("in_child :pid = %d  ppid = %d\n",getpid(),getppid());
        exit(1);/*退出子进程*/
    }else{/*父进程*/
        printf("in_parent :pid = %d  ppid = %d\n",getpid(),getppid());
    }


    return 0;/*退出当前函数，返回0*/
}
