#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_ctrl_c_handler(int signo)
{
    if(SIGINT == signo)	{
      printf("I have received the SIGINT signal!\n");
    }
}


void sig_quit_handler(int signo)
{
    if (SIGQUIT == signo) {
	printf("I have received the SIGQUIT signal!\n");
	exit(1);
    }
}

int main(void)
{
    int times = 1;
    printf("Signal demo\n");
#if 0    
    //..安装信号处理的句柄
    signal(SIGINT, sig_handler);  //信号处理方式1： 捕获信号
//    signal(SIGINT,SIG_IGN);  //信号处理方式2： 忽略信号
    //signal(SIGINT, SIG_DFL); //信号处理方式3： 默认处理方式
    signal(SIGQUIT, sig_handler);
#else
    sigset_t set, oldset;
    
    struct sigaction act;

    /*把SIGINT,SIGQUIT加入到set集合中,并调用sigprocmask()阻塞它们 */
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    sigprocmask(SIG_BLOCK, &set, NULL);

    /* 安装SIGINT,SIGQUIT的信号处理的方法*/
    act.sa_handler = sig_ctrl_c_handler;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags=SA_RESTART;
    sigaction(SIGINT,&act, NULL);
    
    act.sa_handler = sig_quit_handler;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,SIGINT);
    sigaction(SIGQUIT,&act,NULL);

    sigprocmask(SIG_UNBLOCK, &set, NULL);
    
    sigpending(&set);  /*检查系统中被延迟的SIGINT,SIGQUIT信号，如果有,这时候可以送到程序中来处理了 */

    /* 专门处理SIGCHLD信号，让父进程不调用wait()/waitpid()，子进程也不会变成僵尸进程 */
    act.sa_handler = SIG_DFL;
    sigemptyset(&act.sa_mask);
    act.sa_flags =SA_NOCLDWAIT |SA_RESTART;
    sigaction(SIGCHLD, &act,NULL); 

    //后续父进程fork()子进程时，不需要调用wait()/waitpid()去回收子进程
     //子进程退出时，会直接释放内存   
   
    //后续是真正的读到数据的处理流程 
    //...

#endif

    printf("after install the signal handler\n");

    while(1) {
	printf("I'm the %d times loop!\n", times++);
	sleep(1);
    }	
    return 0;
}
