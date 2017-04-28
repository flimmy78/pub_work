/*******************************************************************
 *   > File Name: 03-pthread3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 28 Apr 2017 03:50:09 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[] = "Hello World";
int run_now = 1;

int main(int argc, char* argv[])
{
    int res;
    pthread_t a_thread; 
    void *thread_result;
    
    /* create a pthread */
    if((res = pthread_create(&a_thread, NULL, thread_function, (void*)message)) != 0){
        perror("pthread creation failed");exit(EXIT_FAILURE);
    }

    int print_count1 = 0;

    while(print_count1 ++ < 20){
        if(run_now == 1){
            printf("1");
            fflush(stdout);
            run_now = 2;
        }else{
            sleep(1);
        }
    }

    /* join a pthread */
    printf("Waiting for thread to finish...\n");
    if((res = pthread_join(a_thread, &thread_result)) != 0){
        perror("pthread join error");exit(EXIT_FAILURE);
    }
    
    printf("Thread joined , it returned %s\n", (char*)thread_result);
    printf("Message is now %s\n", message);

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){
#if (1)
    int print_count2 = 0;

    while(print_count2 ++ < 20){
        if(run_now == 2){
            printf("2");
            fflush(stdout);
            run_now = 1;
        }else{
            sleep(1);
        }
    }
#endif
    printf("thread_function is running . Arguments was %s\n", (char*)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the CPU time");
}
