/*******************************************************************
 *   > File Name: 21-ValTest.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 30 Mar 2017 03:39:59 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int Val = 0;

int main(int argc, char* argv[])
{

    pid_t pid;
    int counter = 0;

    pid = fork();
    if(pid < 0){
        printf("fork error\n");exit(EXIT_FAILURE);
    }else if(pid == 0){
        while(1){
            if(Val != 0){
                printf("Child :Val is change\n");
            }
        }
    }
    sleep(1);
    while(1){
        sleep(1);
        Val = ~Val;
        counter ++;
        printf("Parent : counter = %d  Val = %d\n",counter,Val);
    }

    return 0;
}
