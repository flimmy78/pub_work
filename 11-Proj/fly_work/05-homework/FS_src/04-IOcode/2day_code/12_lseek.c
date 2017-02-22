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

    if(argc != 3){
	fprintf(stderr,"Usage:%s [file_path] [SIZE]\n",argv[0]);
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
    
    int len,ret;
    
    len = atoi(argv[2]);
    /******************创建大小为len的空洞文件**************************/
    //1.将文件位移量增加到len位置
    ret = lseek(fd,len,SEEK_SET);
    printf("ret = %d\n",ret);

    //2.在该位移量位置写入结束信息
    lseek(fd,-3,SEEK_CUR);
    strcpy(buf,"end");
    my_write(fd,buf,strlen(buf));

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
