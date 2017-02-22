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

    //从管道中读取数据,并打印到屏幕上
    while(1){
	bzero(buf,BUFSIZ);
	read(fd,buf,BUFSIZ);
	if(strncmp(buf,"quit",4) == 0)
	    break;
	printf("%d:%s",getpid(),buf);
    }
    return 0;
}
