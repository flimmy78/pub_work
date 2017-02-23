#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc,char **argv)
{
    pid_t pid;
    int fd1,fd2;
    char buf[BUFSIZ];

    if(argc != 3){
        fprintf(stderr,"Usage:%s [fifo_name1] [fifo_name2]\n",argv[0]);
        exit(1);
    }


    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }else if(pid == 0){   //子进程：Jack向管道fd1中写数据
        //打开有名管道
        if((fd1 = open(argv[1],O_WRONLY)) < 0){
            perror("open");
            exit(1);
        }
        while(1){
            bzero(buf,BUFSIZ);
            //printf("%d ",getpid());
            fgets(buf,BUFSIZ,stdin);
            write(fd1,buf,strlen(buf));
            if(strncmp(buf,"quit",4) == 0)
                break;
        } 
        exit(0);
    }else{   //父进程：Jack从管道fd2中读数据,并将数据打印出来
        //打开有名管道
        if((fd2 = open(argv[2],O_RDONLY)) < 0){
            perror("open");
            exit(1);
        }
        while(1){
            bzero(buf,BUFSIZ);
            if(read(fd2,buf,BUFSIZ) > 0){
                if(strncmp(buf,"quit",4) == 0)
                    break;
                printf("%s:%s","Rose",buf);
            }
        }
        exit(0);
    }
    return 0;
}
