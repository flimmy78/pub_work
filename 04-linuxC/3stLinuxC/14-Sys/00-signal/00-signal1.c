#include <stdio.h>  

#include <signal.h>  

static volatile int signum = 0;  

void sigme(int signo)  

{  

	printf("signal received:%d\n", signum++);  

	sleep(3);  

}  

int main()  

{  

	signal(SIGUSR1, sigme);  

	/*signal(SIGRTMIN, sigme);*/  

	while(1);  

	return 0;  

}  
