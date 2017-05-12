/*******************************************************************
 *   > File Name: 04-pthread4.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 12 May 2017 04:21:45 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main(int argc, char* argv[])
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    
    /*初始化一个互斥锁*/
    res = pthread_mutex_init(&work_mutex, NULL);
    if(res != 0){
        perror("pthread_mutex_init error");exit(EXIT_FAILURE);
    }
    
    /*创建信线程*/
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if(res != 0){
        perror("pthread create error");exit(EXIT_FAILURE);
    }

    pthread_mutex_lock(&work_mutex);    /*加锁*/
    printf("Input some text. Enter 'end' to finish\n");
    while(!time_to_exit){
        fgets(work_area, WORK_SIZE, stdin); /*获取键盘输入*/
        pthread_mutex_unlock(&work_mutex);  /*解锁*/
        while(1){
            pthread_mutex_lock(&work_mutex);    /*加锁*/
            if(work_area[0] != '\0'){
                pthread_mutex_unlock(&work_mutex);  /*解锁*/
                sleep(1);
            }else{
                break;
            }
        }
    }

    pthread_mutex_unlock(&work_mutex);  /*解锁*/
    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);   /*回收线程*/
    if(res != 0){
        perror("pthread join error");exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    pthread_mutex_destroy(&work_mutex); /*摧毁互斥锁*/

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){
    sleep(1);
    pthread_mutex_lock(&work_mutex);

    while(strncmp("end", work_area, 3) != 0){
        printf("You input %d characters\n", strlen(work_area) - 1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while(work_area[0] == '\0'){
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
