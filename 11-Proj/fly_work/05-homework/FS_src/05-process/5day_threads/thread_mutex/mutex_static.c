#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <time.h>
#include <semaphore.h>


int lock_var = 0;

time_t end_time;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  /*互斥锁的静态定义*/

void *thread_routine1(void *arg)
{
	int i;
	printf("I'am the sub thread1\n");

	while(time(NULL) < end_time) {
		//加锁
		pthread_mutex_lock(&mutex);  //P操作
		for(i=0; i<3; i++) {
			lock_var++;
			sleep(1);
			printf("product: lock_var =%d in for loop.\n", lock_var);
		}
		
		printf("product: lock_var =%d\n", lock_var);
		
		pthread_mutex_unlock(&mutex);  //V操作
		usleep(70000); //sleep 0.07s	
	}
	
	pthread_exit(NULL);
	return NULL;
}

void *thread_routine2(void *arg)
{
        printf("I'am the sub thread2\n");

        while(time(NULL) < end_time) {
		pthread_mutex_lock(&mutex);  //P操作
		printf("customer: lock_var=%d\n", lock_var);
		pthread_mutex_unlock(&mutex);  //V操作
		usleep(10000); //sleep 0.01s
	}

        pthread_exit(NULL);
        return NULL;
}

int main(void) 
{
	pthread_t tid1, tid2;
	printf("Thread demo\n");
	
	end_time = time(NULL) +30;
	
	pthread_mutex_init(&mutex, NULL);  //初始化mutex,保护的对象是lock_var
			
        pthread_create(&tid1, NULL, thread_routine1, NULL);
	pthread_create(&tid2, NULL, thread_routine2, NULL);
       	printf("after pthread_create()\n"); 
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&mutex); /* 删除互斥锁  */

	printf("after pthread_join()\n");

	return 0;
}
