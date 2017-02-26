/*******************************************************************
 *   > File Name: 01-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Feb 2017 01:32:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    while(1){
        printf("ppid = %d pid = %d test process\n",getppid(),getpid());
        sleep(1);
    }
    return 0;
}
