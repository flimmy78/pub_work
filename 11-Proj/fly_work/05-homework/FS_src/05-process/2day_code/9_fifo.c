#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc,char **argv)
{
    pid_t pid;
    int fd;
    char buf[BUFSIZ];

    if(argc != 2){
	fprintf(stderr,"Usage:%s [fifo_name]\n",argv[0]);
	exit(1);
    }

    //打开有名管道
    if((fd = open(argv[1],O_RDWR)) < 0){
	perror("open");
	exit(1);
    }

    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid == 0){   //子进程：小明向管道中写数据
	while(1){
	    bzero(buf,BUFSIZ);
	    printf("%d ",getpid());
	    fgets(buf,BUFSIZ,stdin);
	    write(fd,buf,strlen(buf));
	    if(strncmp(buf,"quit",4) == 0)
		break;
	} 
	exit(0);
    }else{   //父进程：小明他爸从管道中读数据,并将数据打印出来
	while(1){
	    bzero(buf,BUFSIZ);
	    read(fd,buf,BUFSIZ);
	    if(strncmp(buf,"quit",4) == 0)
		break;
	    printf("%d:%s",getpid(),buf);

	}
	exit(0);
    }
    return 0;
}
