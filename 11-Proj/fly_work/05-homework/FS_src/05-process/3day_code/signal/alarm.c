#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signo)
{
    if(SIGALRM == signo)	{
      printf("I have received the SIGALRM signal!\n");
    }

}

int main(void)
{
    int times = 1;
    printf("alarm demo\n");
    
    //..安装信号处理的句柄
    signal(SIGALRM, sig_handler);  //信号处理方式1： 捕获信号
    printf("after install the signal handler\n");
    
    //设置闹钟
    alarm(5); //5s
    printf("after alarm\n");
    pause();  //整个进程通过pause()暂停，直到收到任意信号为止
    printf("after pause\n");

    return 0;
}
