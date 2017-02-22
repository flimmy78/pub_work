#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{

    pid_t pid;
#if 1
    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid == 0){  //子进程中条件成立，进入if执行
	printf("in_child:pid:%d\n",getpid());
	printf("in_child:ppid:%d\n",getppid());
	exit(123);
	//return 200;
    }else    //父进程中条件成立，进入分支语句执行
    {
	int status;
	printf("in_parent:pid:%d\n",getpid());
	printf("in_parent:ppid:%d\n",getppid());
	wait(&status);   //使调用进程阻塞，直到任一子进程结束返回，如果调用进程没有子进程，wait直接返回
	printf("status : %d\n",status);	
	printf("exit:%d\n", WEXITSTATUS(status));  //获取子进程返回的值
    }
#else
    printf("hello\n");
    wait(NULL);   //调用进程没有子进程，直接返回
    printf("world\n");
#endif
    return 0;
}
