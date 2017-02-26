/*******************************************************************
 *   > File Name: 04-exec.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Feb 2017 05:28:19 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }else if(pid > 0){
        int i;
        for(i = 0; i< 10; i++){
            printf("i = %dd\n",i);
            sleep(1);
        }
    }else{
#if (1)
        execl("/bin/ls","ls","-l",NULL);
#else
        char *str[] = {"ls","-l",NULL};
        execvp("ls",str);
        execlp("ls","ls","-l",NULL);
#endif
    }

    return 0;
}
