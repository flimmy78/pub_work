#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <time.h>
#include <semaphore.h>


int lock_var = 0;

time_t end_time;
sem_t sem;

void *thread_routine1(void *arg)
{
	int i;
	printf("I'am the sub thread1\n");

	while(time(NULL) < end_time) {
		//加锁
		sem_wait(&sem); // Psem 操作
		for(i=0; i<3; i++) {
			lock_var++;
			sleep(1);
			printf("product: lock_var =%d in for loop.\n", lock_var);
		}
		
		printf("product: lock_var =%d\n", lock_var);
		
		sem_post(&sem);  //Vsem操作
		usleep(70000); //sleep 0.07s	
	}
	
	pthread_exit(NULL);
	return NULL;
}

void *thread_routine2(void *arg)
{
        printf("I'am the sub thread2\n");

        while(time(NULL) < end_time) {
		sem_wait(&sem);  //Psem操作
		printf("customer: lock_var=%d\n", lock_var);
		sem_post(&sem);  //Vsem操作
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
	
	sem_init(&sem, 0, 1);  //保护的对象是lock_var
			
        pthread_create(&tid1, NULL, thread_routine1, NULL);
	pthread_create(&tid2, NULL, thread_routine2, NULL);
       	printf("after pthread_create()\n"); 
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("after pthread_join()\n");

	return 0;
}
