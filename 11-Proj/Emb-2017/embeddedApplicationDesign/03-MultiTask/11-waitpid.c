/*******************************************************************
 *   > File Name: 11-waitpid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 14 Dec 2017 07:38:04 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t pid, ret;
    int status;

    if((pid = fork()) < 0){
        printf("Error fork!\n");
    }else if(pid == 0){
        sleep(5);
        exit(100);
    }else{
        do{
            ret = waitpid(pid, &status, WNOHANG);

            if(ret == 0){
                printf("child process has not exited!\n");
                sleep(1);
            }
        }while(ret == 0);
        
        if(ret ==  pid){
            printf("child process has exited , status = %d!\n", WEXITSTATUS(status));
        }else{
            printf("some error occured!\n");
        }
    }

    return 0;
}
