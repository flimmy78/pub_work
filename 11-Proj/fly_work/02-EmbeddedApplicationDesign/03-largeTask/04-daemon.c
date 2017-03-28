/*******************************************************************
 *   > File Name: 04-daemon.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Feb 2017 11:25:21 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void init_daemon(void)/*初始化守护进程*/
{
    pid_t pid;

    /*1.创建守护进程*/
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid > 0)
    {
        exit(0);
    }

    /*2.创建新会话*/
    if(setsid() < 0)
    {
        perror("setsid");
        exit(1);
    }

    /*3.再一次创建子进程*/
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }else if(pid > 0)
    {
        exit(0);
    }

    /*4.忽略信号：SIGHUP*/
    signal(SIGHUP, SIG_IGN);

    /*5.关闭所有的文件描述符*/
    int max_fd, i;
    max_fd = sysconf(_SC_OPEN_MAX);
    for(i = 0; i< max_fd; i++)
    {
        close(i);
    }

    /*6.消除umask的影响*/
    umask(0);

    /*7.重新定向标准IO文件描述符*/
    open("/dev/null",O_RDWR);
    dup(0);
    dup(0);
    /*8.修改守护进程的工作目录*/
    chdir("/tmp");
}

int main(int argc, char* argv[])
{
    FILE *fp;
    int count = 0;
    time_t tm;
    char buf[BUFSIZ];

    init_daemon();/*初始化一个守护进程*/

    if((fp = fopen("1.txt","a+")) < 0)
    {
        perror("fopen");
        exit(1);
    }

    while(fgets(buf, BUFSIZ, fp) != NULL)
        count ++;
    while(1)
    {
        time(&tm);
        sprintf(buf, "Daemon %2d:%s", count++,(char *)ctime(&tm));
        fputs(buf,fp);
        fflush(fp);
        printf("%s",buf);
        sleep(1);
    }

    return 0;
}
