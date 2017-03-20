/*******************************************************************
 *   > File Name: 99-simple_fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 20 Mar 2017 11:37:47 PM CST
 ******************************************************************/
#if (0)
#include <unistd.h>
pid_t fork(void);
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pret;

    pret = fork();
    if(pret == -1){
        perror("fork err");exit(EXIT_FAILURE);
    }else if(pret == 0){
        printf("In child process ! pret is %d, My PID is %d , PPID is %d .\n", pret, getpid(), getppid());
    }else if(pret > 0){
        printf("In parent process ! pret is %d, My PID is %d , PPID is %d .\n", pret, getpid(), getppid());
    }

    wait(NULL);

    return 0;
}
