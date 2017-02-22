#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int fd;

    umask(0222);

    fd = open("1.txt",O_RDONLY|O_CREAT,0666);   
    if(fd < 0){
	perror("open");
	exit(1);
    }

    char buf[BUFSIZ];
    read(fd,buf,BUFSIZ);
    printf("%s\n",buf);

    close(fd);
    return 0;
}
