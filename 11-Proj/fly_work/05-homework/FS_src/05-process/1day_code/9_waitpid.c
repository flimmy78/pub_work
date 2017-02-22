#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid1,pid2;
    int i;

    if((pid1 = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid1 == 0){   //子进程1
	//子进程1执行
	printf("I am child process 1\n");
	for(i = 0; i < 10; i++){
	    printf("in_child1:i = %d\n",i);
	    sleep(1);
	}
	exit(0);
    }else{
	if((pid2 = fork()) < 0){
	    perror("fork");
	    exit(1);
	}else if(pid2 == 0){   //子进程2
	    //子进程2执行
	    printf("I am child process 2\n");
	    for(i = 0; i < 5; i++){
		printf("in_child2:i = %d\n",i);
		sleep(1);
	    }
	    
	    exit(0);
	}
    }
    waitpid(-1,NULL,0);
    printf("pid = %d\n",getpid());
    return 0;
}
