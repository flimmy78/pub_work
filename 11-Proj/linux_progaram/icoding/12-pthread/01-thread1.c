/*******************************************************************
 *   > File Name: 01-thread1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 27 Apr 2017 01:51:23 PM CST
 ******************************************************************/
#if (0)
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);
int pthread_join(pthread_t thread, void **retval);
void pthread_exit(void  *retval);
#endif

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread_function(void *arg);
char message[] = "This is a test\n";

int main(int argc, char* argv[])
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
    if(res != 0){
        perror("Thread creation failed");exit(EXIT_FAILURE);
    }

    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if(res != 0){
        perror("Thread join failed");exit(EXIT_FAILURE);
    }

    printf("Thread joined, it returned %s\n", (char*)thread_result);
    printf("Message is now %s\n", message);

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){
    static int i = 0;
    printf("thread_function is running . Argument was %s\n", (char*)arg);//获取参数
    //sleep(3);
    for(i = 0; i< 3; i++){
        printf("\tPthread running\n");sleep(1);
    }

    strcpy(message, "Bye!");    //修改全局变量
    pthread_exit("Thank you for the CPU time");
}
