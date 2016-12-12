#include <sys/time.h>
#include <stdio.h>

#define DEBUG_TEST

void delay(unsigned int value)
{
	unsigned int i,j;

	for(i = 0; i<value ; i++)
		for(j = 0; j<5000 ; j++)
			;
}

unsigned long delay_time(void)
{
	struct timeval start,end;
	unsigned long diff;
	
	gettimeofday(&start,NULL);
	delay(10);
	gettimeofday(&end,NULL);
	diff = end.tv_sec + end.tv_usec -start.tv_sec - start.tv_usec * 1000000;

	return diff;
}

#ifdef DEBUG_TEST
int main(void)
{
	unsigned long time;

	time = delay_time();
	printf("diff : %ld \n",time);
	
	return 0;
}
#endif
