#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <time.h>
#include <semaphore.h>


int lock_var = 0;

time_t end_time;
sem_t sem1, sem2;

void *thread_routine1(void *arg)
{
	int i;
	printf("I'am the sub thread1\n");

	while(time(NULL) < end_time) {
		//加锁
		sem_wait(&sem1); // Psem1 操作
		for(i=0; i<3; i++) {
			lock_var++;
			sleep(1);
			printf("tmp info: lock_var =%d in for loop.\n", lock_var);
		}
		
		printf("product: lock_var =%d\n", lock_var);
		
		sem_post(&sem2);  //Vsem2操作
	}
	
	pthread_exit(NULL);
	return NULL;
}

void *thread_routine2(void *arg)
{
        printf("I'am the sub thread2\n");

        while(time(NULL) < end_time) {
		sem_wait(&sem2);  //Psem2操作
		printf("customer: lock_var=%d\n", lock_var);
		sem_post(&sem1);  //Vsem1操作
	}

        pthread_exit(NULL);
        return NULL;
}

int main(void) 
{
	pthread_t tid1, tid2;
	printf("Thread demo\n");
	
	end_time = time(NULL) +30;
	
	sem_init(&sem1, 0, 1);  //保护的对象是lock_var
	sem_init(&sem2, 0, 0);
		
        pthread_create(&tid1, NULL, thread_routine1, NULL);
	pthread_create(&tid2, NULL, thread_routine2, NULL);
       	printf("after pthread_create()\n"); 
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("after pthread_join()\n");

	return 0;
}
