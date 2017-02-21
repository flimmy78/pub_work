#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define DEBUG_TEST

int check_settime(char *time_str){
	time_t set_sec,sys_sec;	/*定义系统和设定时间*/
	char t_str[19];
	char *simple = "xxxx-xx-xx_xx:xx:xx";	/*年-月-日_小时：分钟：秒*/
	strncpy(t_str,time_str,strlen(simple));
	int absVal;     /*定义系统与设定时间的绝对值*/

	struct tm tm_t;
	sscanf(t_str,"%d-%d-%d_%d:%d:%d",\
			&tm_t.tm_year,\
			&tm_t.tm_mon,\
			&tm_t.tm_mday,\
			&tm_t.tm_hour,\
			&tm_t.tm_min,\
			&tm_t.tm_sec);	/*给结构体tm_t填充数据*/

	tm_t.tm_year -= 1900;	/*转换成UTC时间*/
	tm_t.tm_mon -= 1;
	//tm_t.tm_hour -= 8;	/*?为何不减去8*/

	set_sec = mktime(&tm_t);			/*设定时间*/
	sys_sec = time((time_t *)NULL);		/*系统时间*/
	absVal = abs(set_sec - sys_sec);
	printf("set_sec[%ld] sys_sec[%ld]\ttime_diff[%d]\n",set_sec,sys_sec,absVal);

	if(absVal < 10){
		return 1;	/*差值小于10s,使用系统时间*/
	}else{
		return 0;	/*差值不小于10s，更新系统时间*/
	}
}

#ifdef DEBUG_TEST
#if 0
int main(void)
{	
	char Str[19];
	memset(Str,0,sizeof(Str));
	fprintf(stdout,"Pls Input :");
	scanf("%s",Str);

	printf("%d\n",check_settime(Str));
	return 0;
}
#else
int main(int argc,char **argv)
{
	if(argc < 2)
	{
		printf("Usage :%s XXXX-XX-XX_XX:XX:XX\n",argv[0]);
		exit(EXIT_FAILURE);
	}
    
    int res;
	if((res = check_settime(argv[1])) != 1){
        printf("Time will be changed\n");
    }
	return 0;
}
#endif
#endif
