#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>

void *thread_routine(void *arg)
{
   char *str =(char *)arg;
   printf("I'm sub thread, arg =%s\n", str);
   sleep(2);
   pthread_exit(NULL);  
}

int main(void)
{

    printf("Threads demo!\n");
    printf("I'm the main thread!\n");
    
    pthread_t tid;
    char *string = "Hello, 1604 class";

    /* 创建子线程*/
    pthread_create(&tid, NULL, thread_routine, (void *)string); 

    printf("I'm the main thread, after pthread_create()\n");
    
    pthread_join(tid, NULL);
    printf("I'm the main thread, after pthread_join()\n");
    
  //...父线程的执行空间
    
    return 0;
}
