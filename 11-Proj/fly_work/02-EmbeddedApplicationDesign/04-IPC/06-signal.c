/*******************************************************************
 *   > File Name: 06-signal.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Feb 2017 03:36:12 PM CST
 ******************************************************************/
/*头文件*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/*自定义信号处理函数*/
void my_func(int sign_no){
    if(sign_no == SIGINT){
        printf("I have got SIGINT\n");
    }else if(sign_no == SIGQUIT){
        printf("I have got SIGQUIT\n");
    }
}

int main(int argc, char* argv[])
{
    printf("Waiting for signal SIGINT or SIGQUIT ...\n");

    /*设置信号处理函数*/
    signal(SIGINT, my_func);
    signal(SIGQUIT, my_func);
    pause();

    return 0;
}
