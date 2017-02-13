/*******************************************************************
 *   > File Name: 02-execlp.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 11:25:44 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int ret;

    if(fork() == 0)
    {
        /*调用execlp()函数，这里相当于调用了“ps -ef”命令*/
        if((ret = execlp("ps","ps","-ef",NULL)) < 0)
        {
            printf("execlp error\n");
        }
    }

    return 0;
}
