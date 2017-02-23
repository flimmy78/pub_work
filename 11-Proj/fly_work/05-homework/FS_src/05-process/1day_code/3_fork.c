#include <stdio.h>
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
	sleep(1);
    return 0;
}
