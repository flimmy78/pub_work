/*******************************************************************
 *   > File Name: 02-fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Feb 2017 01:36:14 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

void func(void){
    int i;

    for(i = 0; i< 5; i++){
        printf("in_func :%d\n",i);
        sleep(1);
    }
}

int main(int argc, char* argv[])
{
    int i;

    if(fork() == 0){
        func();
        printf("I am child process !\n");
        exit(1);
    }

    for(i = 0; i< 5; i++){
        printf("in_main:%d\n",i);
        sleep(1);
    }

    sleep(1);

    return 0;
}
