/*******************************************************************
 *   > File Name: 09-fifo1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 15 May 2017 04:53:56 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int res = mkfifo("/tmp/my_fifo", 0777);
    if(res == 0){
        printf("FIFO created\n");
    }

    return 0;
}
