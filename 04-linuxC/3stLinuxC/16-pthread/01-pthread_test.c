/*******************************************************************
 *   > File Name: 01-pthread_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 16 Feb 2017 02:29:24 PM CST
 ******************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *ThreadFunc()
{
    static int count = 1;
    printf ("Create thread %d\n", count);
    pthread_detach (pthread_self());/*线程分离*/
    count++;

}

main(void)
{
    int     err;
    pthread_t tid;
    while (1){
        err = pthread_create(&tid, NULL, ThreadFunc, NULL);
        if (err != 0){
            printf("can't create thread: %s\n", strerror(err));
            break;
        }  
    }
}
