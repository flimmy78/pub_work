#include <stdio.h>
#include <stdlib.h>
int main(void)
{

    pid_t pid;

    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid == 0){  //子进程中条件成立，进入if执行
	printf("in_child:pid:%d\n",getpid());
	printf("in_child:ppid:%d\n",getppid());
	exit(1);
    }else    //父进程中条件成立，进入分支语句执行
    {
	printf("in_parent:pid:%d\n",getpid());
	printf("in_parent:ppid:%d\n",getppid());
	
    }
   // sleep(1);
    return 0;
}
