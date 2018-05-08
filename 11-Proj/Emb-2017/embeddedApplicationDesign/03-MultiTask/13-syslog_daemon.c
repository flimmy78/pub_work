/*******************************************************************
 *   > File Name: 13-syslog_daemon.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Dec 2017 06:08:26 AM PST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    pid_t pid ,sid;
    int i, fd;
    char* buf = "This is a daemon test !\n";

    /*打开系统日志文件*/
    openlog("13-syslog_daemon", LOG_PID|LOG_PERROR, LOG_DAEMON);

    if((pid = fork()) < 0){
        syslog(LOG_ERR,"fork err\n");
        exit(1);
    }else if(pid > 0){
        exit(0);
    }

    if((sid = setsid()) < 0){
        syslog(LOG_ERR, "%s\n", "setsid");
        exit(1);
    }


    if((sid = chdir("/")) < 0){
        syslog(LOG_ERR, "%s\n", "chdir");
        exit(1);
    }

    umask(0);

    for(i = 0; i< getdtablesize(); i++){
        close(i);
    }

    while(1){
        if((fd = open("/tmp/daemon.log", O_CREAT|O_WRONLY|O_APPEND, 0600)) < 0){
            syslog(LOG_ERR, "open");
            exit(1);
        }

        write(fd, buf,sizeof(buf) + 1);

        close(fd);
        sleep(1);
    }

    closelog();

    return 0;
}
