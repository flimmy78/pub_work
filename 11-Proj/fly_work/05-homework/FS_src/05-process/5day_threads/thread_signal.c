#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include <pthread.h>

sigset_t set;

void *thread_routine(void *arg)
{
   char *str =(char *)arg;
   printf("I'm sub thread, arg =%s\n", str);
   
   sleep(2);
   pthread_exit(NULL);  
}

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

void *sig_handle_routine(void *arg)
{
   printf("I'm sig_handle thread!\n");
    struct sigaction act;
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

    pthread_sigmask(SIG_UNBLOCK, &set, NULL);
      
    sigpending(&set);  /*检查系统中被延迟的SIGINT,SIGQUIT信号，如果有,这时候可以送到程序中来处理了 */    
 
    int loop = 0;
    while(1) {
        printf("I'm the signal handler thread, loop =%d\n", ++loop);
        sleep(2);  
    };

   pthread_exit(NULL);
}

int main(void)
{

    printf("Threads demo!\n");
    printf("I'm the main thread!\n");
    
    pthread_t tid,sig_tid;
    char *string = "Hello, 1604 class";

    /*主线程中屏蔽SIGINT和SIGQUIT */
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    /* 创建子线程*/
    pthread_create(&tid, NULL, thread_routine, (void *)string); 
    /*设置子线程的分离属性，使得父线程不需要pthread_join()回收子线程 */
    pthread_detach(tid);
    
    pthread_create(&sig_tid, NULL, sig_handle_routine, NULL);
    pthread_detach(sig_tid);

    printf("I'm the main thread, after pthread_create()\n");
    
  //父线程
    int loop = 0;
    while(1) {
	printf("I'm the main thread, loop =%d\n", ++loop);
	sleep(1);
    }
    

    return 0;
}
