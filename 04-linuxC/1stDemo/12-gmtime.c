#include <stdio.h>
#include <time.h>

int fun(void)
{
	time_t timep;
	struct tm *p_time_tm;

	time(&timep);
	p_time_tm = gmtime(&timep);
	printf("Seconds :%d\n",p_time_tm->tm_sec);			/*秒*/
	printf("Minutes :%d\n",p_time_tm->tm_min);			/*分钟*/
	printf("Hours :%d\n",p_time_tm->tm_hour + 8);		/*小时*/
	printf("Day of the month :%d\n",p_time_tm->tm_mday);	/*日份*/
	printf("Month :%d\n",p_time_tm->tm_mon + 1);			/*月份*/
	printf("Year :%d\n",p_time_tm->tm_year + 1900);			/*年份*/
	printf("Day of the week :%d\n",p_time_tm->tm_wday);
	printf("Day in the year :%d\n",p_time_tm->tm_yday);
	printf("Daylight saving time :%d\n",p_time_tm->tm_isdst);
	
	return 0;
}

int main(void)
{
	return fun();
}
