/*******************************************************************
 *   > File Name: 04-pthread.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 17 Feb 2017 03:00:56 PM CST
 ******************************************************************/
#if (0)
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
int pthread_attr_init(pthread_attr_t *attr);
int pthread_detach(pthread_t thread);
int pthread_join(pthread_t thread, void **retval);
//线程执行函数内，使用分离属性，线程回收不正常
#endif
/*头文件*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*函数声明*/
int pthread_setstacksize(pthread_attr_t *attr, size_t stacksize);
void *pthread_function(void *arg);
void *pthread_FUNC(void *arg);

int main(int argc, char* argv[])
{
    pthread_t pid_function, pid_FUNC;
    pthread_attr_t attr_function, attr_FUNC;

    if(pthread_setstacksize(&attr_function, 250000) != 0)
    {
        printf("pthread_setstacksize attr_function err\n");
    }
    if(pthread_setstacksize(&attr_FUNC, 250000) != 0)
    {
        printf("pthread_setstacksize attr_FUNC err\n");
    }

    if(pthread_create(&pid_function,&attr_function,pthread_function,NULL) != 0)
    {
        perror("pthread_create pid_function err");
    }

    if(pthread_create(&pid_FUNC, &attr_FUNC, pthread_FUNC, NULL) != 0)
    {
        perror("pthread_create pid_FUNC err");
    }

    if(pthread_join(pid_FUNC,NULL) != 0)
    {
        perror("pthread_join pid_function err");
    }else
    {
        printf("pthrad_join pid_function OK\n");
    }

    if(pthread_join(pid_function, NULL) != 0)
    {
        perror("pthread_join pid_FUNC err");
    }else
    {
        printf("pthread_join pid_FUNC OK\n");
    }

    return 0;
}

int pthread_setstacksize(pthread_attr_t *attr, size_t stacksize){
    if(pthread_attr_init(attr) != 0)
    {
        printf("%s :pthread_attr_init err\n",__func__);return (-1);
    }
    if(pthread_attr_setstacksize(attr, stacksize))
    {
        printf("%s :pthread_attr_setstacksize err\n",__func__);return (-1);
    }

    return 0;
}

void *pthread_function(void *arg){
#if (0)
    if(pthread_detach(pthread_self()) != 0)
    {
        printf("%s :pthread_detach err\n",__func__);
        return NULL;
    }
#endif

        static int j = 0;
        for(j = 0; j< 3; j++)
        {
            printf("\t%s [%s] (%d)----%d In child pthread\n",__FILE__,__func__,__LINE__,j);
            sleep(2);
        }
    
    return NULL;
}


void *pthread_FUNC(void *arg){
#if (0)
    if(pthread_detach(pthread_self()) != 0)
    {
        printf("%s :pthread_detach err\n",__func__);
        return NULL;
    }
#endif

    //while(0)
    {
        static int i = 0;
        for(i = 0; i< 8; i++)
        {
            printf("%s [%s] (%d)----%d In child pthread\n",__FILE__,__func__,__LINE__,i);
            sleep(1);
        }
    }

    return NULL;
}
