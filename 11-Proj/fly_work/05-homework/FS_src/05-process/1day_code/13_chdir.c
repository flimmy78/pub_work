#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int fd1;
    char buf[BUFSIZ];

    chdir("/");   //修改当前工作目录
    if((fd1 = open("1.txt",O_WRONLY|O_CREAT|O_APPEND,0644)) < 0){
	perror("open");
	exit(1);
    }

    fgets(buf,BUFSIZ,stdin);
    write(fd1,buf,strlen(buf));

    close(fd1);
    return 0;
}
