/*******************************************************************
 *   > File Name: 00-fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 30 Nov 2017 11:47:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t ret;

    ret = fork();

    if(ret == -1){
        perror("fork error ");exit(EXIT_FAILURE);
    }else if(ret == 0){
        printf("In child process ! ret is %d, My PID is %d\n", ret, getpid());
    }else{
        printf("In parent process ! ret is %d, My PID is %d\n", ret, getpid());
    }

    return 0;
}
