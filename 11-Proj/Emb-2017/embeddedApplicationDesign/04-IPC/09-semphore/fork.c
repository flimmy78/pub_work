/*******************************************************************
 *   > File Name: fork.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 Jan 2018 06:08:18 AM PST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DELAY_TIME  3   /*为了突出显示效果，等待几秒钟*/

int main(int argc, char* argv[])
{
    pid_t result;
    int sem_id;

    sem_id = semget(ftok(".", 'a'), 1, 0666|IPC_CREAT);/*创建信号量*/
    init_sem(sem_id, 0);

    /*调用fork（）函数*/
    result = fork();
    if(result == -1){
        perror("Fork\n");
    }else if(result == 0){/*返回值为0代表子进程*/
        printf("Child process will wait for some seconds...\n");
        sleep(DELAY_TIME);
        printf("The returned value is %d in the child process (PID = %d)\n",\
                result , getpid());
        sem_v(sem_id);
    }else{/*返回值大于0代表父进程*/
        sem_p(sem_id);
        printf("The returned value is %d in the father process (PID = %d)\n",\
                result, getpid());
        sem_v(sem_id);
        del_sem(sem_id);
    }

    return 0;
}
