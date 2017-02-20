
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

/*
 *int gettimeofday(struct timeval *tv, struct timezone *tz);
 *
 *struct timeval {
 *	time_t      tv_sec;     // seconds 
 *	suseconds_t tv_usec;    // microseconds 
 *};
 *
 *struct timezone {
 *	int tz_minuteswest;     // minutes west of Greenwich,和Greenwich时间相差多少分钟
 *	int tz_dsttime;         // type of DST correction 
 *};
 * 3>在gettimeofday()函数中tv或者tz都可以为空。如果为空则就不返回其对应的结构体。
 * 4>函数执行成功后返回0，失败后返回-1，错误代码存于errno中。
 */



int main(void)
{
	struct timeval tv;
	struct timezone tz;

	static struct timeval last;
	unsigned long diff = 0;


	gettimeofday(&tv,&tz);

	diff = tv.tv_sec - last.tv_sec;
	printf("diff = %d \n",diff);
	printf("last.tv_sec = %d \n",last.tv_sec);

	printf("tv_sec = %d\n",tv.tv_sec);
	printf("tv_usec = %d\n",tv.tv_usec);

	printf("tz_minuteswest  = %d \n",tz.tz_minuteswest);
	printf("tz_dsttime = %d\n",tz.tz_dsttime);

	return 0;

}
