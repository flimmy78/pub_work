#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    pid_t pid1,pid2;
    int fd[2];

    //父进程创建无名管道
    if(pipe(fd) < 0){
	perror("pipe");
	exit(1);
    }

    if((pid1 = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid1 == 0){   //子进程：哥哥:执行ls
	close(fd[0]);
	dup2(fd[1],STDOUT_FILENO);
	execlp("ls","ls",NULL); 
    }else{     //父进程
	close(fd[1]);
	dup2(fd[0],STDIN_FILENO);
	execlp("wc","wc","-w",NULL);
    }
    return 0;
}
