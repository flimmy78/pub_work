/*******************************************************************
 *   > File Name: 02-pthread.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 16 Feb 2017 06:03:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <time.h>

int pthread_setstacksize(pthread_attr_t *attr, int stacksize)
{
    if(pthread_attr_init(attr) != 0)
    {
        printf("pthread_attr_init error\n");return (-1);
    }

    if(pthread_attr_setstacksize(attr, stacksize) != 0)
    {
        printf("pthread_attr_setstacksize error\n");return (-1);
    }
    return 0;
}

void *pthread_func(void *arg)
{
#if (0)
    if(pthread_detach(pthread_self()) != 0)
    {
        printf("%s : pthread_detach err\n",__func__);
    }
#endif

    int i = 0;
    time_t tm;
    while(1)
    {
        time(&tm);
        fprintf(stdout,"%d : %s\n",i,ctime(&tm));
        i++;
    }

    return NULL;
}

void func_service(void *arg)
{
    pid_t pid;
    pthread_attr_t attr;
	
	if(pthread_setstacksize(&attr, 250000) != 0)
	{
		printf("%s :pthread_setstacksize err\n",__func__);
	}

	if(pthread_create(&pid, &attr,pthread_func, NULL) != 0)
	{
		printf("%s :pthread_create err\n",__func__);
	}
}

int main(int argc, char* argv[])
{
    
	func_service(NULL);
    return 0;
}
