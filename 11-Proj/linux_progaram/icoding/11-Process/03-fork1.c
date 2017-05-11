/*******************************************************************
 *   > File Name: 03-fork1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 02:20:15 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    char *MSG;
    int n;
    
    printf("Starting fork the process\n");
    pid = fork();
    switch(pid){
        case (-1):
            printf("fork err\n");
            exit(EXIT_FAILURE);
            break;
        case 0:
            MSG = "\tThis is child process";
            n = 3;
            break;
        default:
            MSG = "This is parent process";
            n = 10;
            break;
    }

    for(;n >0; n--){
        puts(MSG);
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}
