/*******************************************************************
 *   > File Name: 01-thread_1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 20 Feb 2017 01:07:34 PM CST
 ******************************************************************/
/*头文件*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*全局变量*/
char massage[] = "this is a test";
/*函数声明*/
void *thread_func(void *arg);

int main(int argc, char* argv[])
{
    int res;/*定义一个整型变量，用于获得函数返回值*/
    pthread_t pid;/*定义一个线程ID*/
    void *thread_result;/*定义一个void指针，指向线程退出返回的值*/

    /*创建线程*/
    if((res = pthread_create(&pid, NULL, thread_func,(char*)massage)) != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    printf("Waiting thread finish...\n");
    
    /*回收线程*/
    if((res = pthread_join(pid, &thread_result)) != 0)
    {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("thread_result : %s \t massage : %s\n",(char *)thread_result,massage);

    return 0;
}

/*线程执行函数*/
void *thread_func(void *arg)
{
    printf("Thread runing , the arg :%s\n",(char*)arg);/*打印获得的参数*/
    sleep(2);
    strcpy(massage, "thread used");
    printf("Thread finishing ...\n");
    pthread_exit("thread_stop");/*退出线程*/
}
