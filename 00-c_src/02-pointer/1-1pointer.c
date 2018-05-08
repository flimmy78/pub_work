/*******************************************************************
 *   > File Name: 1-1pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Feb 26 16:33:05 2018
 ******************************************************************/

#include <stdio.h>

#define	RED		"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define YELLOW	"\e[0;33m"
#define BLUE	"\e[0;34m"
#define PINK	"\e[0;35m"
#define NONE	"\e[m"

int main(int argc, char* argv[])
{
    int hoge = 5;
    int piyo = 10;
	printf(RED"hoge...%d, piyo...%d\n"NONE,hoge, piyo);
	
	int *hoge_p;	/*定义一个指向int型的指针变量hoge_p*/
	
	/*输出每个变量的地址*/
	printf(GREEN"&hoge...%p\n"NONE, &hoge);
	printf(GREEN"&piyo...%p\n"NONE, &piyo);
	printf(GREEN"&hoge_p...%p\n"NONE, &hoge_p);
	
	/*将hoge的地址赋予给hoge_p*/
	hoge_p = &hoge;
	printf(YELLOW"\nhoge_p...%p\n\n"NONE,hoge_p);
	
	/*通过hoge_p输出hoge的值*/
	printf(BLUE"*hoge_p...%d\n"NONE,*hoge_p);
	
	/*通过hoge_p修改hoge的内容*/
	*hoge_p = 100;
	printf(BLUE"hoge...%d\n"NONE,hoge);

    return 0;
}
