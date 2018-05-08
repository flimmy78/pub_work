/*******************************************************************
 *   > File Name: 03-kill_raise.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 03 Jan 2018 07:43:46 AM PST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    int ret;

    /*创建一子进程*/
    if((pid = fork()) < 0){
        perror("fork error\n");
        exit(1);
    }

    if(pid == 0){   /*子进程*/
        /*在子进程中使用raise()函数发出SIGSTOP信号，使子进程暂停*/
        printf("Child (pid : %d) is waiting for any signal\n", getpid());
        raise(SIGSTOP);
        exit(1);
    }else{
        /*在父进程中收集子进程的状态，并调用kill（）函数发送信号*/
        if((waitpid(pid, NULL, WNOHANG)) == 0){
            kill(pid, SIGKILL);
            printf("Parent kill child process %d\n", pid);
        }

        waitpid(pid, NULL, 0);
        exit(0);
    }


    return 0;
}
