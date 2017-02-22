#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>

void *thread_routine(void *arg)
{
   char *str =(char *)arg;
   printf("I'm sub thread, arg =%s\n", str);

   /*设置子线程的分离属性，使得父线程不需要pthread_join()回收子线程 */
   /* 注意： ubuntu12.04中可能系统中存在BUG，会导致此处代码崩溃
    *        那么此时在主线程中去设置子线程的分离属性
    */
  // pthread_detach(pthread_self());
   
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
    /*建议在此处：设置子线程的分离属性，使得父线程不需要pthread_join()回收子线程 */
    pthread_detach(tid);

    printf("I'm the main thread, after pthread_create()\n");
    
    // 设置线程的分离属性后，不再需要 pthread_join(tid, NULL);

   // printf("I'm the main thread, after pthread_join()\n");
    
  //...父线程的执行空间

    sleep(3);

    return 0;
}
