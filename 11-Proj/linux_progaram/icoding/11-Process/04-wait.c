/*******************************************************************
 *   > File Name: 04-wait.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 02:39:28 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    char *MSG;
    int n;
    int exit_code;

    printf("fork program starting\n");
    pid = fork();
    switch(pid){
        case (-1):  //出错
            printf("fork err");
            exit(EXIT_FAILURE);
            break;
        case 0:     //子进程
            MSG = "\tThis is a child process.\n";
            n = 5;
            exit_code = 37;
            break;
        default:    //父进程
            MSG = "This is a parent process.\n";
            n = 3;
            exit_code = 0;
            break;
    }

    for(; n > 0; n--){
        puts(MSG);
        sleep(1);
    }
        
    /*等待子进程完成*/
    if(pid != 0){
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);   

        printf("Child has finished :PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    exit(exit_code);
}
