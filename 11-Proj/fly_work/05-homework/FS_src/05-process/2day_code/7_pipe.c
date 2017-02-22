#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
    int fd[2];
    char buf[BUFSIZ];

    //创建无名管道
    if(pipe(fd) < 0){
	perror("pipe");
	exit(1);
    }
    close(fd[0]);
    strcpy(buf,"hello world");
    if(write(fd[1],buf,strlen(buf)) > 0){
	perror("write");
	exit(1);
    }
    printf("test\n");
    return 0;
}
