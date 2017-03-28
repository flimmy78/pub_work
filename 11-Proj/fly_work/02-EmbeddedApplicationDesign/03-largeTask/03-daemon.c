/*******************************************************************
 *   > File Name: 03-daemon.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Feb 2017 10:34:17 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FILE_FLAGS  (O_CREAT|O_RDWR|O_APPEND)
#define DEFAULT_FILE_FLAGS (O_CREAT|O_WRONLY|O_TRUNC)

void init_daemon(void){
    static pid_t pid;
    static int i;

    if((pid = fork()) < 0){ /*1.创建进程*/
        printf("Error fork\n");exit(EXIT_FAILURE);
    }else if(pid > 0){
        exit(EXIT_SUCCESS); /*2.父进程退出*/
    }

    setsid();               /*3.获取新的会话ID*/
    chdir("/tmp");          /*4.改变工作目录*/
    umask(0);               /*5.改变文件权限*/
    
    for(i = 0; i<getdtablesize(); i++){
        close(i);           /*6.关闭当前进程所有的文件描述符*/
    }
}

int main(int argc, char* argv[])
{
    char *buf = "This is a Daemon Process\n";
    //printf("%s",buf);

    init_daemon();

    /*此时创建完守护进程，以下开始进入守护进程工作*/
    /*此守护进程可被kill杀死*/
    int count = 0, fd;
    FILE *fp;
    if((fd = open("daemon.log", FILE_FLAGS , 0600)) < 0)
    {
        printf("Open file error\n");
        exit(1);
    }
    fp = fdopen(fd,"a");

    while(1)
    {
        fprintf(fp,"%d:%s",count,buf);
        count++;
       // write(fd, buf, strlen(buf));
       // close(fd);
        sleep(2);
        fflush(fp);
    }
    close(fd);

    exit(0);
}
