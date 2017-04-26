/*******************************************************************
 *   > File Name: 03-fork1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 26 Apr 2017 04:29:55 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    char *message;
    int n;
    //int m;

    printf("fork program starting\n");
    pid = fork();

    switch(pid){
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        case 0:
            message = "\tThis is the child";
            n = 5;
            //m = 5;
            break;
        default:
            message = "This is the parent";
            n = 3;
            break;
    }

#if (0)
    for(; m > 0; m--){
        puts(message);
        sleep(1);
    }
#endif

    for(; n > 0; n--){
        puts(message);
        sleep(1);
    }

    wait(NULL);

    return 0;
}
