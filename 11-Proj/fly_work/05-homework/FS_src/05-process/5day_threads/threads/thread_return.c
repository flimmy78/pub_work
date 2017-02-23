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

void *thread_routine(void *arg)
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

int main(void)
{

    struct user_info *pUserInfo = NULL;

    printf("Threads demo!\n");
    printf("I'm the main thread!\n");
    
    pthread_t tid;
    char *string = "Hello, 1604 class";

    /* 创建子线程*/
    pthread_create(&tid, NULL, thread_routine, (void *)string); 

    printf("I'm the main thread, after pthread_create()\n");
    
    pthread_join(tid, (void *)&pUserInfo);

    printf("I'm the main thread, after pthread_join()\n");

    /* 主线程通过pthread_join()获取子线程的返回值并显示 */
    if(pUserInfo != NULL) {
         printf("User info: name is %s, age is %d, sex is %d\n", 
              pUserInfo->name, pUserInfo->age, pUserInfo->sex);     
        free(pUserInfo);
    }
    
    return 0;
}
