/*******************************************************************
 *   > File Name: 11-waitpid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 13 Dec 2017 07:58:05 AM PST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t pid, ret;
    int* status = NULL;

    if((pid = fork()) < 0){
        printf("Error fork!\n");
    }else if(pid == 0){
        sleep(5);

        exit(100);
    }else if(pid > 0){
        do{
            ret = waitpid(pid, status, WNOHANG);

            if(ret == 0){
                printf("The child process has not exited\n");
                sleep(1);
            }

        }while(ret == 0);

        if(pid == ret){
            printf("child process exited, status = %d\n", *status);
        }else{
            printf("some error occured.\n");
        }
    }

    return 0;
}
