#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <stdlib.h>

void init_daemon(void)   //初始化守护进程
{
    /********************start***********************/
    pid_t pid;

    //1.创建子进程
    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid > 0)
	exit(0);
    //2.创建新会话
    if(setsid() < 0){
	perror("setsid");
	exit(1);
    }
    //3.再一次创建子进程
    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid > 0)
	exit(0);
    //4.忽略信号:SIGHUP
    signal(SIGHUP,SIG_IGN);
    //5.关闭所有的文件描述符
    int max_fd,i;
    max_fd = sysconf(_SC_OPEN_MAX);
    for (i = 0; i < max_fd;i++)
	close(i);
    //6.消除umask的影响
    umask(0);
    //7.重新定向标准IO文件描述符
    open("/dev/null",O_RDWR);
    dup(0);
    dup(0);
    //8.修改守护进程的工作目录
    chdir("/");
    /*****************end**************************/
}
int main(void)
{

    FILE *fp,*fp_log;
    int count = 0;
    time_t tm;
    char buf[BUFSIZ];

    init_daemon();   //初始化一个守护进程

    //打开系统日志文件
    openlog("test_log",LOG_DAEMON,LOG_PID);

    if((fp_log = fopen("log","a+")) == NULL){

    }
    if((fp = fopen("1.txt","r+")) == NULL){
	//将错误信息记录在系统日志文件中
#if 0
	syslog(LOG_ERR,"fopen:%s\n",strerror(errno));
#else

	fprintf(fp_log,"%d:fopen:%s\n",getpid(),strerror(errno));
	//fflush(fp_log);
#endif
	exit(1);
    }

    while(fgets(buf,BUFSIZ,fp) != NULL)
	count++;
    while(1){
	time(&tm);
	sprintf(buf,"%d:%s",count++,ctime(&tm));
	fputs(buf,fp);
	fflush(fp);
	syslog(LOG_INFO,"%s",buf);
	fflush(fp);
	printf("%s",buf);
	sleep(1);
    }

    closelog();
    return 0;
}
