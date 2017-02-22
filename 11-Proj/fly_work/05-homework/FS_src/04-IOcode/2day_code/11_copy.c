#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1024

int my_write(int write_fd,char buf[],int size);
int main(int argc,char **argv)
{
    int read_fd,write_fd;
    char buf[SIZE];

    if(argc != 3){
	fprintf(stderr,"Usage:%s [src_file_path] [des_file_path]\n",argv[0]);
	exit(1);
    }

    //打开文件
    if((read_fd = open(argv[1],O_RDONLY)) < 0){
	perror("open");
	exit(1);
    }
    if((write_fd = open(argv[2],O_WRONLY|O_CREAT|O_EXCL|O_TRUNC,0644)) < 0){
	if(errno == EEXIST)
	    write_fd = open(argv[2],O_WRONLY|O_TRUNC);
	else{
	    fprintf(stderr,"%d open:%s\n",errno,strerror(errno));
	    exit(1);
	}
    }
#if 1
    //拷贝文件内容到另一个文件中
    int ret;
    while(1){
	bzero(buf,SIZE);
	if((ret = read(read_fd,buf,SIZE)) < 0){    //从read_fd中读数据
	    perror("read");
	    exit(1);
	}else if(ret == 0)
	    break;
	if(my_write(write_fd,buf,strlen(buf)) < 0){   //将buf中的数据写入文件中
	    perror("my_write");
	    exit(1);
	}
	fprintf(stdout,"%s",buf);	//将buf打印到屏幕
    }
#endif
    //关闭文件
    if(close(read_fd) < 0){
	perror("close");
	exit(1);
    }
    if(close(write_fd) < 0){
	perror("close");
	exit(1);
    }

    return 0;
}

int my_write(int write_fd,char buf[],int size)
{
    int ret = 0,count = size;

    while(1){
	if((ret = write(write_fd,buf+ret,count)) < 0)
	    return -1;
	if(ret == count)
	    break;
	count -= ret;
    }
    return size;
}
