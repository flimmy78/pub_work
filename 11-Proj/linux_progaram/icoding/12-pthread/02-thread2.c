/*******************************************************************
 *   > File Name: 02-thread2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 27 Apr 2017 06:17:01 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[] = "Hello World";

int main(int argc, char* argv[])
{   
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
    if(res != 0){
        perror("Thread creation failed");exit(EXIT_FAILURE);
    }

#if (1)
    int run_now = 1;
    int print_count1 = 0;

    while(print_count1 ++ < 20){
        if(run_now == 1){
            printf("1");
            run_now = 2;
        }else{
            sleep(1);
        }
    }
#endif

    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if(res != 0){
        perror("Thread join failed");exit(EXIT_FAILURE);
    }

    printf("Thread joined ,it returned %s\n", (char*)thread_result);
    printf("Message is now %s\n", message);


    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){
    printf("thread_function is running. Argument was %s\n", (char*)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the CPU time");
}
