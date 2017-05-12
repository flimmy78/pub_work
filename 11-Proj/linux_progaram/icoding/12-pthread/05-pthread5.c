/*******************************************************************
 *   > File Name: 05-pthread5.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 12 May 2017 05:51:30 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello world";
int thread_finished = 0;

int main(int argc, char* argv[])
{   
    int res;
    pthread_t a_thread;         /*定义一个线程ID*/
    pthread_attr_t thread_attr; /*定义一个线程属性*/
    
    /*初始化一个线程属性*/
    res = pthread_attr_init(&thread_attr);
    if(res != 0){
        perror("pthread_attr_init error");exit(EXIT_FAILURE);
    }
    
    /*设置线程的分离属性*/
    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if(res != 0){
        perror("Setting detached attribute failed");exit(EXIT_FAILURE);
    }
    
    /*创建线程*/
    res = pthread_create(&a_thread, &thread_attr, thread_function, (void*)message);
    if(res != 0){
        perror("pthread_create error");exit(EXIT_FAILURE);
    }
    
    /*摧毁线程属性*/
    (void)pthread_attr_destroy(&thread_attr);

    while(!thread_finished){
        printf("Waiting for thread to say it's finished...\n");sleep(1);
    }
    
    printf("Other thread finished ,bye!\n");
    return 0;
}

void *thread_function(void *arg){
    printf("thread_function is running . Argument was %s\n", (char*)arg);
    sleep(4);
    printf("Second thread setting finished flag, and exiting now\n");
    thread_finished = 1;
    pthread_exit(NULL);
}
