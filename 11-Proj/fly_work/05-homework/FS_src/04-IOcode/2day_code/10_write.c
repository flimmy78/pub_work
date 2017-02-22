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

    //向屏幕中写入数据
    printf("STDIN_FILENO : %d\n",STDIN_FILENO);
    while(1){
	bzero(buf,SIZE);
	fgets(buf,SIZE,stdin);   //从键盘获取字符传
	if(my_write(STDIN_FILENO,buf,strlen(buf)) < 0){   //将buf中的数据写到标准输出
	    perror("my_write");
	    exit(1);
	}
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
