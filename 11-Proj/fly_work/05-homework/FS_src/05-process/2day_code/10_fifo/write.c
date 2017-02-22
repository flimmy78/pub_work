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

    //从键盘接收数据，并写入管道中
    while(1){
	bzero(buf,BUFSIZ);
	printf("%d ",getpid());
	fgets(buf,BUFSIZ,stdin);
	write(fd,buf,strlen(buf));
	if(strncmp(buf,"quit",4) == 0)
	    break;
    } 
    return 0;
}
