/*******************************************************************
 *   > File Name: 08-execve.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 07:43:16 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

/*int execve(const char *filename, char *const argv[],
 *                   char *const envp[]);
 * */

/*命令参数列表，必须以NULL结尾*/
char *filename = "/usr/bin/env";
char *argv[] = {"env", NULL};
char *envp[] = {"PATH=/tmp", "USER=harry", NULL};

int main(int argc, char* argv[])
{
    if(fork() == 0){
        if(execve(filename, argv, envp) < 0){
            printf("execve error\n");
        }
    }
    

    return 0;
}
