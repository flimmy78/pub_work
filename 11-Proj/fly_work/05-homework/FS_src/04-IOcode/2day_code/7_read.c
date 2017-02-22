#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 20

int main(int argc,char **argv)
{
    int fd;
    char buf[SIZE];
    int ret;

    if(argc != 2){
	fprintf(stderr,"Usage:%s [file_path]\n",argv[0]);
	exit(1);
    }

    //打开文件
    if((fd = open(argv[1],O_RDONLY|O_CREAT|O_EXCL,0644)) < 0){
	if(errno == EEXIST)
	    fd = open(argv[1],O_RDONLY);
	else{
	    fprintf(stderr,"%d open:%s\n",errno,strerror(errno));
	    exit(1);
	}
    }

    //读取文件内容
    while(1){
	bzero(buf,SIZE);
	if((ret = read(fd,buf,SIZE)) < 0){
	    perror("read");
	    exit(1);
	}else if(ret == 0)
	    break;
	else
	    fprintf(stdout,"%s",buf);
    }
    //关闭文件
    if(close(fd) < 0){
	perror("close");
	exit(1);
    }

    return 0;
}
