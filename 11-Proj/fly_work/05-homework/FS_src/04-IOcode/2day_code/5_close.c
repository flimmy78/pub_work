#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int fd;
    //打开文件
    fd = open("1.txt",O_RDONLY|O_CREAT|O_EXCL,0644);
    if(fd < 0){
	perror("open");
	exit(1);
    }

    //对文件读写

    //关闭文件
    if(close(fd) < 0){
	perror("close");
	exit(1);
    }

    return 0;
}
