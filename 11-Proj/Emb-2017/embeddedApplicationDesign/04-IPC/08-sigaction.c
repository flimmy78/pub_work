/*******************************************************************
 *   > File Name: 08-sigaction.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 04 Jan 2018 07:41:18 AM PST
 ******************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void my_func(int sign_no){
    if(sign_no == SIGINT){
        printf("I have got SIGINT\n");
    }else if(sign_no == SIGQUIT){
        printf("I have got SIGQUIT\n");
    }
}

int main(int argc, char* argv[])
{
    struct sigaction action;

    /*sigaction结构初始化*/
    sigaction(SIGINT, 0, &action);
    action.sa_handler =  my_func;
    sigaction(SIGINT, &action, 0);

    sigaction(SIGQUIT, 0, &action);
    action.sa_handler = my_func;
    sigaction(SIGQUIT, &action, 0);

    printf("Waiting for signal SIGINT or SIGQUIT ...\n");

    pause();

    return 0;
}
