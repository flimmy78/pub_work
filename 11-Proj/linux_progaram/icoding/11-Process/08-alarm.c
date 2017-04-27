/*******************************************************************
 *   > File Name: 08-alarm.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 27 Apr 2017 11:00:33 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
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
        case -1:
            perror("fork error");exit(EXIT_FAILURE);
        case 0:
            sleep(5);
            kill(getppid(), SIGALRM);
            exit(EXIT_SUCCESS);
    }

    printf("waiting for alarm to go off\n");
    (void)signal(SIGALRM, ding);

    pause();
    if(alarm_fired){
        printf("Ding!\n");
    }

    printf("Done\n");

    return 0;
}
