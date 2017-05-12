/*******************************************************************
 *   > File Name: 09-ctrlc2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 12 May 2017 10:19:39 AM CST
 ******************************************************************/
#if (0)
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};
#endif

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
    
    /*examine and change a signal action*/
    sigaction(SIGINT, &act, 0);

    while(1){
        printf("Hello World!\n");
        sleep(1);
    }

    return 0;
}
