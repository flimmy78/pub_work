#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FLOCK

int main(int argc,char **argv)
{
    int fd;

    if(argc != 2){
	fprintf(stderr,"Usage: %s [filename]\n",argv[0]);
	exit(1);
    }

    if((fd = open(argv[1],O_WRONLY|O_CREAT,0644)) < 0){
	perror("open");
	exit(1);
    }

    int i;
    //给文件上锁
#ifdef FLOCK
    struct flock  fl = {F_WRLCK,SEEK_SET,10000,1000};
    if(fcntl(fd,F_SETLKW,&fl) < 0){
	perror("fcntl");
	exit(1);
    }
#endif
    lseek(fd,10000,SEEK_SET);
    for(i = 0; i < 10;i++){
	printf("process2:i = %d\n",i);
	write(fd,"test_process2_flock\n",strlen("test_process2_flock\n"));
	sleep(1);
    }
    //解锁
#ifdef FLOCK
    fl.l_type = F_UNLCK;
    if(fcntl(fd,F_SETLK,&fl) < 0){
	perror("fcntl");
	exit(1);
    }
#endif

    close(fd);
    return 0;
}
