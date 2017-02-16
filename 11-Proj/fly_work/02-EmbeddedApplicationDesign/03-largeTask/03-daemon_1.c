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

int main(int argc, char* argv[])
{
    pid_t pid;
    int i, fd;

    char *buf = "This is a Daemon\n";

    pid = fork();/*第一步*/
    if(pid < 0)
    {
        printf("Error fork\n");
        exit(1);
    }
    else if(pid > 0)
    {
        exit(1);/*父进程退出*/
    }

    setsid();/*第二步*/
    chdir("/tmp");/*第三步*/
    umask(0);/*第四步*/

    for(i = 0; i< getdtablesize(); i++)/*第五步*/
    {
        close(i);
    }

    /*此时创建完守护进程，以下开始进入守护进程工作*/
    /*此守护进程可被kill杀死*/
    int count = 0;
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
