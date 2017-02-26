/*******************************************************************
 *   > File Name: 07-sigaction.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 03:42:15 PM CST
 ******************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/*自定义信号处理函数*/
void my_func(int sign_no){
    if(sign_no == SIGINT){
        printf("I have got SIGINT\n");
    }else if(sign_no == SIGQUIT){
        printf("I have got SIGQUIT");
    }
}

int main(int argc, char* argv[])
{
    struct sigaction action;

    /*sigaction结构初始化*/
    sigaction(SIGINT, 0, &action);
    action.sa_handler = my_func;
    sigaction(SIGINT, &action, 0);

    sigaction(SIGQUIT, 0, &action);
    action.sa_handler = my_func;
    sigaction(SIGQUIT, &action, 0);
    printf("Waiting for signal SIGINT or SIGQUIT...\n");

    pause();

    return 0;
}
