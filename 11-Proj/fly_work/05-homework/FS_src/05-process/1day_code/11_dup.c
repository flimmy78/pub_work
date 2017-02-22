#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int oldfd,newfd;
    char buf[BUFSIZ];

    if((oldfd = open("1.txt",O_WRONLY|O_CREAT|O_APPEND,0644)) < 0){
	perror("open");
	exit(1);
    }

    fgets(buf,BUFSIZ,stdin);
    write(oldfd,buf,strlen(buf));
#if 1
    newfd = dup(oldfd);  //复制文件描述符
    printf("newfd = %d\n",newfd);
    fgets(buf,BUFSIZ,stdin);
    write(newfd,buf,strlen(buf));

#endif
    close(oldfd);
    return 0;
}
