#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_TEST

int check_settime(char *time_string)
{
	time_t sys_time,set_time;
	char t_string[19];
	char *simple = "xxxx-xx-xx_xx:xx:xx";
	strncpy(t_string, time_string, strlen(simple));
	struct tm time_tm;

	sscanf(t_string,"%d-%d-%d_%d:%d:%d",\
			&time_tm.tm_year, \
			&time_tm.tm_mon, \
			&time_tm.tm_mday, \
			&time_tm.tm_hour, \
			&time_tm.tm_min, \
			&time_tm.tm_sec);

	time_tm.tm_year -= 1900;
	time_tm.tm_mon -= 1;
	time_tm.tm_hour -= 8;
	
	set_time = mktime(&time_tm);
	sys_time = time(NULL);

	printf("set_time is %ld ,sys_time is %ld .\n",set_time,sys_time);
	if((set_time > sys_time) && (set_time - sys_time > 10 ) || (set_time < sys_time) && (sys_time - set_time > 10) || set_time == sys_time)
	{
		printf("set_time[%ld] sys_time[%ld] differ[%ld] , time no change !\n",set_time,sys_time,abs(set_time - sys_time));
		return 1;
	}
	else
	{
		printf("set_time[%ld] sys_time[%ld] differ[%ld] , time will be change !\n",set_time,sys_time,abs(set_time - sys_time));
		return 0;
	}
}

#ifdef DEBUG_TEST
int main(void)
{
	int ret;
	char str[19];
	fprintf(stdout,"Pls Input :");
	scanf("%s",str);
	
	ret=check_settime(str);
	printf("ret = %d\n",ret);
	return 0;
}
#endif
