/*******************************************************************
 *   > File Name: 07-ctrlc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 05:51:15 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ouch(int sig){
    printf("OUCH ! - I got signal %d\n", sig);
    (void)signal(SIGINT, SIG_DFL);  /*恢复默认行为*/
}

int main(int argc, char* argv[])
{
    (void)signal(SIGINT, ouch);

    while(1){
        printf("Hello World!\n");
        sleep(1);
    }

    return 0;
}
