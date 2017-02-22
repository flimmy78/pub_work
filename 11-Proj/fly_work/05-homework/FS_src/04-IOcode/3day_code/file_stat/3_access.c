#include <stdio.h>
#include <unistd.h>
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
    if(access("1.txt",R_OK) < 0){
	printf("1.txt 没有可读权限\n");
	exit(1);
    }
    fd = open("1.txt",O_RDONLY);   //以只写方式打开，如果文件存在则清空,不存在则创建
    if(fd < 0){
	perror("open");
	exit(1);
    }

    char buf[BUFSIZ];
    read(fd,buf,BUFSIZ);
    printf("%s\n",buf);

    close(fd);
#endif
    return 0;
}
