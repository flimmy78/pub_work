#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1024

int my_write(int fd,char buf[],int size);
int main(int argc,char **argv)
{
    int fd;
    char buf[SIZE];

    if(argc != 2){
	fprintf(stderr,"Usage:%s [file_path]\n",argv[0]);
	exit(1);
    }

    //打开文件
    if((fd = open(argv[1],O_WRONLY|O_CREAT|O_EXCL|O_TRUNC,0644)) < 0){
	if(errno == EEXIST)
	    fd = open(argv[1],O_WRONLY|O_TRUNC);
	else{
	    fprintf(stderr,"%d open:%s\n",errno,strerror(errno));
	    exit(1);
	}
    }

    //向文件中写入数据
    while(1){
	bzero(buf,SIZE);
	fgets(buf,SIZE,stdin);   //从键盘获取字符传
	if(my_write(fd,buf,strlen(buf)) < 0){   //将buf中的数据写入文件中
	    perror("my_write");
	    exit(1);
	}
	fprintf(stdout,"%s",buf);	//将buf打印到屏幕
    }

    //关闭文件
    if(close(fd) < 0){
	perror("close");
	exit(1);
    }

    return 0;
}

int my_write(int fd,char buf[],int size)
{
    int ret = 0,count = size;

    while(1){
	if((ret = write(fd,buf+ret,count)) < 0)
	    return -1;
	if(ret == count)
	    break;
	count -= ret;
    }
    return size;
}
