#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int fd1,fd2;
    char buf[BUFSIZ];

    if((fd1 = open("1.txt",O_WRONLY|O_CREAT|O_APPEND,0644)) < 0){
	perror("open");
	exit(1);
    }
    if((fd2 = open("2.txt",O_WRONLY|O_CREAT|O_APPEND,0644)) < 0){
	perror("open");
	exit(1);
    }

    fgets(buf,BUFSIZ,stdin);
    write(fd1,buf,strlen(buf));
    dup2(fd1,fd2);  //将fd2重定向到fd1
    fgets(buf,BUFSIZ,stdin);
    write(fd2,buf,strlen(buf));

    close(fd1);
    close(fd2);
    return 0;
}
