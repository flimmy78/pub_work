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
    int pid, times = 1;
    printf("Signal demo\n");
    
    if( (pid = fork()) < 0) {
	perror("fork");
	exit(1);
    }
    //子进程中的代码
    if(0 == pid) {
	//..安装信号处理的句柄
	 signal(SIGINT, sig_handler);  //信号处理方式1： 捕获信号
    //   signal(SIGINT,SIG_IGN);  //信号处理方式2： 忽略信号
    //	 signal(SIGINT, SIG_DFL); //信号处理方式3： 默认处理方式
	 signal(SIGQUIT, sig_handler);

         printf("after install the signal handler\n");
     
	while(1) {
	    printf("I'm the %d times loop!\n", times++);
	
	    sleep(1);
	}
	exit(0);	
    }

    //接下的代码是在父进程中
    sleep(5); //确保子进程先运用并安装好了信号处理的句柄
    kill(pid, SIGINT);
    sleep(3);
    kill(pid, SIGKILL); //杀死子进程
    int status; 
    wait(&status);  //回收子进程的退出
    if(WIFEXITED(status)) {
	printf("The child process is terminated normally\n");
    }
    if(WIFSIGNALED(status)) {
	printf("The child process is terminated by a signal!\n");    
    }
        

    return 0;
}
