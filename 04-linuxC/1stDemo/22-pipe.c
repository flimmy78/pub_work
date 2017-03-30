/*******************************************************************
 *   > File Name: 22-pipe.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 30 Mar 2017 03:52:45 PM CST
 ******************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int pfd[2];
    int counter = 0;
    pid_t pid;
    char BUF[128];
    char *MSG = "This is a pipe test";

    if(pipe(pfd) != 0){
        perror("pipe err");exit(EXIT_FAILURE);
    }
    
    pid = fork();
    if(pid < 0){
        perror("fork err");exit(EXIT_FAILURE);
    }else if(pid == 0){
        close(pfd[1]);
        if(read(pfd[0],BUF,128) > 0){
            printf("Child read from pipe :%s\n",BUF);
        }
    }
    close(pfd[0]);
    write(pfd[1],MSG,strlen(MSG));
    sleep(2);


    return 0;
}
