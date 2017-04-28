/*******************************************************************
 *   > File Name: 02-pthread2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 28 Apr 2017 09:37:15 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[] = "THIS IS A TEST";
int run_now = 1;

int main(int argc, char* argv[])
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    
    /* create a pthread */
    if((res = pthread_create(&a_thread, NULL, thread_function, (void*)message)) != 0){
        perror("pthread_create error");exit(EXIT_FAILURE);
    }
    
    int print_count1 = 0;

    while(print_count1 ++ < 20){
        if(run_now == 1){
            printf("1\n");
            sleep(1);
            run_now = 2;
        }else{
            sleep(1);
        }
    }

    printf("Waiting for thread to finish ...\n");
    /* join a pthread */
    if((res = pthread_join(a_thread, &thread_result)) != 0){
        perror("pthread_join error");exit(EXIT_FAILURE);
    }

    printf("Thread joined , it returned %s\n", (char*)thread_result);
    printf("Message is now %s\n", message);
    
    exit(EXIT_SUCCESS);
}

void *thread_function(void* arg){
#if (1)
    int print_count2 = 0;

    while(print_count2 ++ < 20){
        if(run_now == 2){
            printf("\t2\n");
            sleep(1);
            run_now = 1;
        }else{
            sleep(1);
        }
    }
#endif

    printf("thread_function is running. Argument was %s\n", (char*)arg);
    sleep(3);
    printf("End sleep 3\n");
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the CPU time");
}
