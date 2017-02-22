#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signo)
{
    if(SIGINT == signo)	{
      printf("I have received the SIGINT signal!\n");
    } else if (SIGQUIT == signo) {
	printf("I have received the SIGQUIT signal!\n");
	exit(1);
    }

}

int main(void)
{
    int times = 1;
    printf("Signal demo\n");
    
    //..安装信号处理的句柄
    signal(SIGINT, sig_handler);  //信号处理方式1： 捕获信号
//    signal(SIGINT,SIG_IGN);  //信号处理方式2： 忽略信号
    //signal(SIGINT, SIG_DFL); //信号处理方式3： 默认处理方式
    signal(SIGQUIT, sig_handler);
    printf("after install the signal handler\n");

    while(1) {
	printf("I'm the %d times loop!\n", times++);
	sleep(1);
    }	
    return 0;
}
