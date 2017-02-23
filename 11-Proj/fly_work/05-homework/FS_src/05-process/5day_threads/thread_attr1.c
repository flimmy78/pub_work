#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define USER_NAME_LEN 65
#define FARSIGHT "farsight"

struct user_info {
    char name[USER_NAME_LEN];
    int age;
    int sex;
    //...
};

void *init_data_routine(void *arg)
{
   struct user_info *pUser = (struct user_info *)malloc(sizeof(struct user_info));
   if(!pUser) {  //malloc()分配失败
      pthread_exit(NULL);
   }
        
   char *str =(char *)arg;
   printf("I'm sub thread, tid is 0x%x, arg =%s\n",(int)pthread_self(), str);

   //初始化数据 
   bzero(pUser->name, USER_NAME_LEN); 
   strncpy(pUser->name, FARSIGHT, strlen(FARSIGHT)); 
   pUser->age = 18;
   pUser->sex = 1;
   
   pthread_exit((void *)pUser);  
}

void *thread_routine(void *arg)
{
   char *str =(char *)arg;
   printf("I'm the detach thread, arg =%s\n", str);
   
   pthread_exit(NULL);
}

int main(void)
{

    struct user_info *pUserInfo = NULL;

    printf("Threads demo!\n");
    printf("I'm the main thread!\n");
    
    pthread_t tid1, tid2;
    char *string = "Hello, 1604 class";
    
    pthread_attr_t  attr;
    
   /* 初始化属性变量 */
   pthread_attr_init(&attr);
    /*设置线程的分离属性 */
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    /* 把线程的栈大小扩大一倍 */
    size_t stacksize;
    pthread_attr_getstacksize(&attr,&stacksize);
    pthread_attr_setstacksize(&attr, 2*stacksize);       
    printf("The default thread stack size is: %d, to expend to %d\n", stacksize, 2*stacksize);
 
/* 创建子线程*/
    pthread_create(&tid1, NULL, init_data_routine, (void *)string); 
    pthread_create(&tid2, &attr, thread_routine, (void *)string);
    pthread_attr_destroy(&attr);

    printf("I'm the main thread, after pthread_create()\n");
    
    pthread_join(tid1, (void *)&pUserInfo);
    //不需要等待tid2: pthread_join(tid2, NULL);

    printf("I'm the main thread, after pthread_join()\n");

    /* 主线程通过pthread_join()获取子线程的返回值并显示 */
    if(pUserInfo != NULL) {
         printf("User info: name is %s, age is %d, sex is %d\n", 
              pUserInfo->name, pUserInfo->age, pUserInfo->sex);     
        free(pUserInfo);
    }

    sleep(1);
 
    return 0;
}
