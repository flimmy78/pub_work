#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int fd;
#if 0
    fd = open("1.txt",O_RDONLY|O_CREAT|O_EXCL,0644);
    if(fd < 0){
	perror("open");
	exit(1);
    }
#else
    fd = open("1.txt",O_WRONLY|O_TRUNC|O_CREAT,0644);   //以只写方式打开，如果文件存在则清空,不存在则创建
    if(fd < 0){
	perror("open");
	exit(1);
    }
#endif
    return 0;
}
