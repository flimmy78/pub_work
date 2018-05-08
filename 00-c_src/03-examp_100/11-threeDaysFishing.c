/*******************************************************************
 *   > File Name: 11-threeDaysFishing.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jan 26 17:10:40 2018
 ******************************************************************/
 
 /*
*中国有句俗语叫“三天打鱼两天晒网”。某人从1990年1月1日起开始“三天打鱼两天晒网”，
*问这个人在以后的某一天中是在“打鱼”，还是在“晒网”。
*问题分析与算法设计：
*1.计算从1990年1月1日开始至指定日期一共有多少天；
*2.由于“打鱼”和“晒网”的周期为5天，所以将计算出的天数用5去除；
*3.根据余数判断他是在“打鱼”，还是在“晒网”：
*	若余数为1、2、3，则他是在“打鱼”；
*	否则，是在“晒网”。
 */

#include <stdio.h>

struct date{
	int year;
	int month;
	int day;
};
int days(struct date day);

int main(void){
	struct date today,term;
	int yearday,year,day;
	
	printf("Enter year/month/day:");
	scanf("%d/%d/%d",&today.year, &today.month, &today.day);	/*输入日期*/
	printf("\e[0;32m%d/%d/%d\e[m\r\n", today.year, today.month, today.day);
	
	//term.year = 1990;	/**/
	term.month = 12;	/*设置变量的初始值：月*/
	term.day = 31;		/*设置变量的初始值：日*/
	
	/*------------------------------------------------------------------*/
	for(yearday = 0, year = 1990; year < today.year; year ++){
		term.year = year;
		yearday += days(term);	/*计算从1990年至指定年的前一年共有多少天*/
	}
	
	yearday += days(today);
	day = yearday % 5;
	
	if(day == 1 || day == 2 || day==3){
        printf("today is fishing\n");
    }else{
        printf("today is sleeping\n");
    }
    
    return 0;
	/*------------------------------------------------------------------*/
}

int days(struct date day){
	static int day_tab[2][13] = {	/*二维数组形式的天数表作为参数*/
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,},	/*平年每月的天数*/
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,},	/*闰年每月的天数*/
	};
	
	int i, lp;
	lp = ((day.year%4 == 0 && day.year%100 != 0) || day.year%400 == 0);	/*判定year为闰年还是平年，lp = 0为平年，非0为闰年*/
	
	for(i = 1; i< day.month; i++)
		day.day += day_tab[lp][i];
	
	return (day.day);
}



