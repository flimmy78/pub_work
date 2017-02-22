#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char **argv)
{
    int fd;

    if(argc != 2){
	fprintf(stderr,"Usage: %s [filename]\n",argv[0]);
	exit(1);
    }

    if((fd = open(argv[1],O_WRONLY|O_CREAT|O_APPEND,0644)) < 0){
	perror("open");
	exit(1);
    }

    int i;
    //给文件上锁
    if(flock(fd,LOCK_EX) < 0){
	perror("flock");
	exit(1);
    }
    for(i = 0; i < 10;i++){
	printf("process2:i = %d\n",i);
	write(fd,"test_process2_flock\n",strlen("test_process2_flock\n"));
	sleep(1);
    }
    //解锁
    if(flock(fd,LOCK_UN) < 0){
	perror("flock");
	exit(1);
    }

    close(fd);
    return 0;
}
