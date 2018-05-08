/*******************************************************************
 *   > File Name: 14-multi_proc_wrong.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 18 Dec 2017 05:54:09 AM PST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t child1, child2, child;

    /*创建两个子进程*/
    child1 = fork();
    child2 = fork();

    /*子进程1的出错处理*/
    if(child1 == -1){
        printf("Child1 fork error\n");
        exit(1);
    }else if(child1 == 0){/*子进程1*/
        printf("In Child :execlcute 'ls -l'\n");
        if(execlp("ls", "ls", "-l", NULL) < 0){
            printf("Child execlp error\n");
        }
    }

    if(child2 == -1){/*子进程2的出错处理*/
        printf("Child2 fork error\n");
        exit(1);
    }else if(child2 == 0){/*子进程2中使其暂停5S*/
        printf("In Child2 : sleep for 5 seconds and then exit\n");
        sleep(5);
        exit(0);
    }else{/*在父进程中等待两个子进程退出*/
        printf("In father process:\n");
        child = waitpid(child1, NULL, 0);/*阻塞式等待*/

        if(child == child1){
            printf("Get child1 exit code\n");
        }else{
            printf("Wait child1 Error occured!\n");
        }
    
        do{
            child = waitpid(child1, NULL, WNOHANG);/*阻塞式等待*/

            if(child == 0){
                printf("The child2 process has not exited !\n");
                sleep(1);
            }
        }while(child == 0);

        if(child == child2){
            printf("Get child2 exit code \n");
        }else{
            printf("Wait child2 Error occured!\n");
        }

    }

    return 0;
}
