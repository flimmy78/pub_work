#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void fun(void)
{
    int i;

    for(i = 0;i < 5; i++){
	printf("in_fun:%d\n",i);
	sleep(1);
    }
}

int main(void)
{
    int i;

    if(fork() == 0){
	fun();
	printf("I am child process!\n");
	exit(1);
    }
    for(i = 0;i < 5; i++){
	printf("in_main:%d\n",i);
	sleep(1);
    }
    wait(NULL);
    return 0;
}
