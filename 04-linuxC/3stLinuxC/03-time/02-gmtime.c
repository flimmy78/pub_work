#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t sys_time;
	struct tm *tm_time;

	/*取得目前的时间，单位：s*/
	sys_time = time((time_t *)NULL);

	/*将目前时间sys_time转换成日常的时间表现格式*/
	tm_time = gmtime(&sys_time);
	//mktime(tm_time);
	printf("time :%ld\n",sys_time);
	printf("秒：%d\n",tm_time->tm_sec);
	printf("分钟：%d\n",tm_time->tm_min);
	printf("小时：%d\n",tm_time->tm_hour + 8);
	printf("日份：%d\n",tm_time->tm_mday);
	printf("月份：%d\n",tm_time->tm_mon + 1);
	printf("年份：%d\n",tm_time->tm_year + 1900);
	printf("星期：%d\n",tm_time->tm_wday);
	printf("天数：%d\n",tm_time->tm_yday);
	printf("夏令时：%d\n",tm_time->tm_isdst);

	struct tm *p;
	p = localtime(&sys_time);
	printf("local秒：%d\n",p->tm_sec);
	printf("local分钟：%d\n",p->tm_min);
	printf("local小时：%d\n",p->tm_hour );
	printf("local日份：%d\n",p->tm_mday);
	printf("local月份：%d\n",p->tm_mon + 1);
	printf("local年份：%d\n",p->tm_year + 1900);
	printf("local星期：%d\n",p->tm_wday);
	printf("local天数：%d\n",p->tm_yday);
	printf("local夏令时：%d\n",p->tm_isdst);
	/*将tm_tlocalime所指向的结构体数据转换成秒*/
	printf("time : %ld\n",mktime(p));
	return 0;
}
