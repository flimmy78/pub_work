#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{

    pid_t pid;

    if((pid = fork()) < 0){
	perror("fork");
	exit(1);
    }else if(pid > 0){ //父进程
	int i;
	for(i = 0 ; i < 10;i++){
	    printf("i =%d\n",i);
	    sleep(1);
	}
    }else{    //子进程
#if 1
	execl("/bin/ls","ls","-l",NULL);	//在子进程中加载另一个程序ls
#else
	char *str[] = {"ls","-l",NULL};
	execvp("ls",str);	//在子进程中加载另一个程序ls
	execlp("ls","ls","-l",NULL);	//在子进程中加载另一个程序ls
#endif
    }
    return 0;
}
