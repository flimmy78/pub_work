#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define DEBUG_TEST

#if 0
 long long   getcurrenttime(void)
{
	struct timeval tv;
	struct timezone tz;
	long long  total_usec = -1;

	if(gettimeofday(&tv, &tz) != 0)
	{
		perror("gettimeofday error ");
		return -1;
	}

#if (1)
	printf("Seconds : %ld\n",tv.tv_sec);
	printf("Microseconds : %ld\n",tv.tv_usec);
	printf("Minutes west of Greewich : %d\n",tz.tz_minuteswest);
	printf("Type of DST correction : %d\n",tz.tz_dsttime);
#endif

	total_usec = tv.tv_sec * 1000 + tv.tv_usec;

	printf("%s,%lld\n",__func__,total_usec);

	return total_usec;
}
#endif

int getcurrenttime(void)
{
	struct timeval tv;
	struct timezone tz;

	if(gettimeofday(&tv, &tz) != 0)
	{
		perror("gettimeofday error");
		return (-1);
	}

	printf("Seconds : %ld\n",tv.tv_sec);
	printf("Microseconds : %ld\n",tv.tv_usec);
	printf("Minutes west of Greewich : %d\n",tz.tz_minuteswest);
	printf("Type of DST correction : %d\n",tz.tz_dsttime);

	return 0;
}

#ifdef DEBUG_TEST
int main(int ac, char **av)
{
	long long  time;

	if((time = getcurrenttime()) < 0)
	{
		printf("getcurrenttime error \n");
		exit(EXIT_FAILURE);
	}
	printf("time = %lld\n",time);

	exit(EXIT_SUCCESS);
}
#endif
