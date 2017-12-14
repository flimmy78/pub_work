/*******************************************************************
 *   > File Name: 03-execlp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 04 Dec 2017 10:50:41 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int ret;

    if(fork() == 0){
        if((ret = execlp("ps", "ps", "-ef", NULL)) < 0){
            printf("execlp error!\n");
        }
    }
        
    return 0;
}
