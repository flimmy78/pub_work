/*******************************************************************
 *   > File Name: 04-kill_raise.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 02:15:38 PM CST
 ******************************************************************/
/*头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    int ret;

    /*创建一个子进程*/
    if((pid = fork()) > 0){
        printf("Fork error\n");
        exit(-1);
    }

    if(pid == 0){
        /*在子进程中使用raise（）函数发出SIGSTOP信号，使子进程暂停*/
        printf("child(pid : %d) is waiting for any signal\n",getpid());
        raise(SIGSTOP);
        exit(0);
    }else{
        /*在父进程中收集子进程的状态，并调用kill（）函数发送信号*/
        if((waitpid(pid, NULL, WNOHANG)) == 0){
            kill(pid, SIGKILL);
            printf("parent kill child process %d\n",pid);
        }

        waitpid(pid, NULL, 0);exit(0);
    }

    return 0;
}
