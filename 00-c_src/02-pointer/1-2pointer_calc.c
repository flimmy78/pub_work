/*******************************************************************
 *   > File Name: 1-2pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Feb 26 17:05:31 2018
 ******************************************************************/

#include <stdio.h>

#define	RED		"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define YELLOW	"\e[0;33m"
#define BLUE	"\e[0;34m"
#define PINK	"\e[0;35m"
#define NONE	"\e[m"

int main(void){
	#if (0)
	int hoge = 5;
	void hoge_p;//Error:variable or field 'hoge_p' declared void
	
	hoge_p = &hoge;
	printf("%d\n", hoge_p);
	#endif
	
	/*------------------------------------------------*/
	int hoge;
	int *hoge_p;
	
	/*将指向hoge的指针赋予hoge_p*/
	hoge_p = &hoge;
	
	/*输出hoge_p的值*/
	printf(PINK"hoge_p...%p\n"NONE, hoge_p);
	
	/*给hoge_p加1*/
	hoge_p++;
	
	/*输出hoge_p的值*/
	printf(PINK"hoge_p...%p\n"NONE, hoge_p);
	
	/*输出hoge_p加3后的值*/
	printf(PINK"hoge_p...%p\n"NONE, hoge_p+3);
	
	return 0;
}