/*******************************************************************
 *   > File Name: 08-alarm.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 12 May 2017 09:16:24 AM CST
 ******************************************************************/
#if (0)
#include <sys/types.h>
#include <signal.h>

int kill(pid_t pid, int sig);
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
#endif

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig){
    alarm_fired = 1;
}

int main(int argc, char* argv[])
{
    pid_t pid;

    printf("alarm application starting\n");

    pid = fork();
    switch(pid){
        case (-1):
            perror("fork err");
            exit(EXIT_FAILURE);
        case 0:
            sleep(5);
            /*send a signal to a process or a group of process
             * */
            kill(getppid(), SIGALRM);
            exit(1);
    }

    printf("Waiting for alarm to go off\n");
    (void)signal(SIGALRM, ding);//信号操作函数

    pause();
    if(alarm_fired)
        printf("Ding!\n");

    printf("done!\n");

    return 0;
}
