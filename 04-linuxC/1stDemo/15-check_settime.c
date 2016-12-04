#include <stdio.h>
#include <string.h>
#include <time.h>

#define DEBUG_TEST

int check_settime(char *time_string)
{
	time_t set_sec, sys_sec;
	char t_string[19];
	char *sample = "xxxx-xx-xx_xx:xx:xx";
	strncpy(t_string, time_string, strlen(sample));
	struct tm time_tm;
	sscanf(t_string, "%d-%d-%d_%d:%d:%d",\
			&time_tm.tm_year,\
			&time_tm.tm_mon,\
			&time_tm.tm_mday,\
			&time_tm.tm_hour,\
			&time_tm.tm_min,\
			&time_tm.tm_sec);

	time_tm.tm_year -= 1900;    /* 转换成UTC时间 */
	time_tm.tm_mon -= 1;        /* 转换成UTC时间 */
	set_sec = mktime(&time_tm); /* 将time_tm所指向的数据结构转换成秒 */
	time(&sys_sec); /* 取得目前的时间 */

	printf("\n time:......set_sec[%ld]..sys_sec[%ld]...\n", set_sec, sys_sec);

	if(set_sec > sys_sec && (set_sec - sys_sec < 10) || (sys_sec > set_sec && (sys_sec - set_sec < 10)) || (sys_sec == set_sec))
	{
		printf("...set_sec[%ld]..sys_sec[%ld]...< 10s time not change..............\n", sys_sec, sys_sec);
		return 1;
	}
	else
	{
		printf("...set_sec[%ld]..sys_sec[%ld]...will change..............\n", set_sec, sys_sec);
		return 0;
	}
}

#ifdef DEBUG_TEST
int main(void)
{
	char time_str[19];
	printf("Pls input:");
	scanf("%s",time_str);
	
	return check_settime(time_str);
}
#endif
