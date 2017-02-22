#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello World";

int main() {
#if (0)
    if(pthread_detach(pthread_self()) != 0)
    {
        printf("pthread_detach err\n");
    }
#endif
    int res;//返回值
    pthread_t a_thread;//线程ID
    void *thread_result;//线程传递出来的参数
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);/*创建线程*/
    if (res != 0) {/*线程创建出错*/
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    /*--------------------------*/
	static int j = 0;
	for(j = 0; j < 3; j++)
	{
		printf("%d :Parent process !\n",j);
		sleep(1);
	}
    printf("Waiting for thread to finish...\n");
#if (1)
    res = pthread_join(a_thread, &thread_result);/*使主线程等待指定的线程结束*/
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, it returned %s\n", (char *)thread_result);
#endif
    printf("Message is now %s\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {

#if (0)
    if(pthread_detach(pthread_self()) != 0)
    {
        printf("pthread_detach error\n");
    }
#endif
    printf("thread_function is running. Argument was %s\n", (char *)arg);/*获取参数*/
    sleep(2);
	
	static int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("\t%d :Thread process !\n",i);
		sleep(1);
	}
    strcpy(message, "Bye!");/*修改全局变量*/
    pthread_exit("Thank you for the CPU time");
}
