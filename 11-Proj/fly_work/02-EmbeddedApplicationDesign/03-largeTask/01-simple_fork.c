/*******************************************************************
 *   > File Name: 01-simple_fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 11:08:27 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t ret;
    int i ;

    /*调用fork函数*/
    ret = fork();
    /*通过ret的值来判断fork()函数的返回情况，首先进行出错处理*/
    if(ret == -1)
    {
        perror("fork error");
        return (-1);
    }
    else if(ret == 0)/*返回值为0代表子进程*/
    {
        for(i = 0;i < 3; i++)
        {
            printf("In child process ! ret is %d, My PID is %d\n",ret,getpid());
            sleep(1);
        }
    }
    else/*返回值大于0代表父进程*/
    {
        for(i = 0; i<3; i++)
        {
            printf("In parent process ! ret is %d, My PID is %d\n",ret,getpid());
            sleep(1);
        }
    }

    return 0;
}
