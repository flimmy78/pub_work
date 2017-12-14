/*******************************************************************
 *   > File Name: 06-execl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 07:29:44 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(fork() == 0){
        /*调用execl()函数，注意这里要给出PS程序所在的完整路径*/
        if(execl("/bin/ps", "ps", "-el", NULL) < 0){
            printf("execl error\n");
        }
    }

    return 0;
}
