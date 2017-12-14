/*******************************************************************
 *   > File Name: 07-execle.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 07:36:12 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*命令参数列表，必须以NULL结尾*/
char *envp[] = {"PATH=/tmp", "USER=harry", NULL};

int main(int argc, char* argv[])
{
    if(fork() == 0){
        /*调用execle()函数，注意这里也要指出env的完整路径*/
        if(execle("/usr/bin/env", "env", NULL, envp) < 0){
            printf("execlp error\n");
        }
    }

    return 0;
}
