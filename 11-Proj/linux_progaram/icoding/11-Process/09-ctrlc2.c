/*******************************************************************
 *   > File Name: 09-ctrlc2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 27 Apr 2017 11:42:07 AM CST
 ******************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig){
    printf("OUCH ! - I got signal %d\n", sig);
}

int main(int argc, char* argv[])
{
    struct sigaction act;

    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGINT, &act, 0);

    while(1){
        printf("Hello World !\n");
        sleep(1);
    }

    return 0;
}
