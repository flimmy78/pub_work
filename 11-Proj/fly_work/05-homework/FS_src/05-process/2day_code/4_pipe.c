#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
    pid_t pid;
    int fd[2];
    char buf[BUFSIZ];

    //创建无名管道
    if(pipe(fd) < 0){
	perror("pipe");
	exit(1);
    }

    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid == 0){   //子进程：小明向管道中写数据
	close(fd[0]);
	while(1){
	    bzero(buf,BUFSIZ);
	    printf("%d ",getpid());
	    fgets(buf,BUFSIZ,stdin);
	    write(fd[1],buf,strlen(buf));
	    if(strncmp(buf,"quit",4) == 0)
		break;
	} 
	exit(0);
    }else{   //父进程：小明他爸从管道中读数据,并将数据打印出来
	close(fd[1]);
	while(1){
	    bzero(buf,BUFSIZ);
	    read(fd[0],buf,BUFSIZ);
	    if(strncmp(buf,"quit",4) == 0)
		break;
	    printf("%d:%s",getpid(),buf);

	}
	exit(0);
    }
    return 0;
}
