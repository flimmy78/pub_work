/*******************************************************************
 *   > File Name: 12-daemon.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 15 Dec 2017 09:17:33 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    int i, fd;
    char* buf = "This is a Daemon !\n";

    pid = fork();   /*1.创建子进程*/
    if(pid < 0){
        printf("Error fork\n");
        exit(1);
    }else if(pid > 0){
        exit(0);
    }

    setsid();       /*2.创建新会话*/

    chdir("/tmp");  /*3.设置工作目录*/

    umask(0);       /*4.重设文件权限掩码*/

    for(i = 0; i < getdtablesize(); i++){
        close(i);   /*5.关闭文件描述符*/
    }

    while(1){
#if (1)
        if((fd = open("/tmp/daemon.log", O_CREAT|O_WRONLY|O_APPEND, 0600)) < 0){
#else
        if((fd = open("/tmp/daemon.log", O_WRONLY|O_APPEND, 0600)) < 0){//error
#endif
            printf("Open file error\n");
            exit(1);
        }

        write(fd, buf, strlen(buf));
        
        sleep(2);
    }
    
    close(fd);
    return 0;
}
