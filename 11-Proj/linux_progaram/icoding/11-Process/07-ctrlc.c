/*******************************************************************
 *   > File Name: 07-ctrlc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 27 Apr 2017 10:17:33 AM CST
 ******************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig){
    printf("OUCH! - I got signal %d\n", sig);
    /*the default action associated with the SIGINT signal occurs*/
    (void)signal(SIGINT, SIG_DFL);
}

int main(int argc, char* argv[])
{   
    /*the  SIGINT signal will run the ouch*/
    (void)signal(SIGINT, ouch);

    while(1){
        printf("This is a test\n");
        sleep(1);
    }

    return 0;
}
