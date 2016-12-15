#include <sys/time.h>
#include <stdio.h>

#define DEBUG_TEST

#if 0
struct timeval {
	time_t      tv_sec;     /* seconds */
	suseconds_t tv_usec;    /* microseconds */
};

truct timezone {
	int tz_minuteswest;     /* minutes west of Greenwich */
	int tz_dsttime;         /* type of DST correction */
};

gettimeofday(struct timeval *tv, struct timezone *tz);
#endif

#ifdef DEBUG_TEST
int main(void)
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv,&tz);

	printf("tv_sec : %d\n",tv.tv_sec);
	printf("tv_usec : %d\n",tv.tv_usec);
	printf("tz_minutestwest : %d\n",tz.tz_minuteswest);
	printf("tz_dattime : %d\n",tz.tz_dsttime);

	return 0;
}
#endif



