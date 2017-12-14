/*******************************************************************
 *   > File Name: 02-fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 03 Dec 2017 09:51:41 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t ret;

    /*调用fork函数*/
    ret = fork();
    /*通过ret的值来判断fork()函数的返回情况，首先进行出错处理*/
    if(ret == -1){
        perror("fork error");return (-1);
    }else if(ret == 0){
        /*返回值为0代表子进程*/
        printf("In child process ! ret is %d, My PID is %d\n", ret, getpid());
    }else{
        /*返回值大于0代表父进程*/
        printf("In parent process ! ret is %d, My PID is %d\n", ret, getpid());
    }
        

    return 0;
}
