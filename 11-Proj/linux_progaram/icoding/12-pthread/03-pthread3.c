/*******************************************************************
 *   > File Name: 03-pthread3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 12 May 2017 01:40:29 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_function(void *arg);
sem_t bin_sem;

#define WORK_SIZE   1024
char work_area[WORK_SIZE];

int main(int argc, char* argv[])
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    
    /*初始化一个信号量,信号量初始值设为0*/
    res = sem_init(&bin_sem, 0, 0);
    if(res != 0){
        perror("Semaphore initialization failed");exit(EXIT_FAILURE);
    }
    
    /*创建新线程*/
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if(res != 0){
        perror("Thread creation failed");exit(EXIT_FAILURE);
    }
    
    /*获得字符串输入*/
    printf("Input some text. Enter 'end' to finish\n");
    while(strncmp("end", work_area, 3) != 0){
        fgets(work_area, WORK_SIZE, stdin);
        sem_post(&bin_sem);//增加信号量
    }

    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if(res != 0){
        perror("Thread join failed");exit(EXIT_FAILURE);
    }
    
    printf("Thread joined\n");
    sem_destroy(&bin_sem);

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){
    sem_wait(&bin_sem); //减去信号量,当信号量大于0时才减
    while(strncmp("end", work_area, 3) != 0){
        printf("You input %d characters\n", strlen(work_area) - 1);
        sem_wait(&bin_sem); //减去信号量
    }
    pthread_exit(NULL);
}
