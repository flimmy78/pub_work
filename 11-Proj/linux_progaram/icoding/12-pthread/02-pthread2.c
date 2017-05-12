/*******************************************************************
 *   > File Name: 01-pthread1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 12 May 2017 11:13:23 AM CST
 ******************************************************************/
#if (0)
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
int pthread_join(pthread_t thread, void **retval);
void pthread_exit(void *retval);
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[] = "Hello world";
int run_now = 1;

int main(int argc, char* argv[])
{
    int res ;
    pthread_t a_thread;
    void *thread_result;
    
    /*create a pthread*/
    res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
    if(res != 0){
        perror("Thread creation failed");exit(EXIT_FAILURE);
    }

    int print_count1 = 0;
    
    while(print_count1 ++ < 20){
        if(run_now == 1){
            printf("1");
            fflush(NULL);
            run_now = 2;
        }else{
            sleep(1);
        }
    }

    printf("Waiting for thread to finish...\n");
    
    /*join the pthread*/
    res = pthread_join(a_thread, &thread_result);
    if(res != 0){
        perror("Thread join failed");exit(EXIT_FAILURE);
    }

    printf("Thread joined, it returned %s\n", (char*)thread_result);
    printf("Message is now %s\n", message);

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){

    int print_count2 = 0;

    while(print_count2 ++ < 20){
        if(run_now == 2){
            printf("2");
            fflush(NULL);
            run_now = 1;
        }else{
            sleep(1);
        }
    }

    printf("thread_function is running. Argument was %s\n", (char *)arg);
    sleep(3);
    strcpy(message, "Bye!");//修改全局变量
    pthread_exit("Thank you for the CPU time");
}
