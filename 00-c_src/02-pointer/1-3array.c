/*******************************************************************
 *   > File Name: 1-3array.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Feb 26 19:50:53 2018
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
	int array[5];
	int i;
	
	/*为数组array的各元素设值*/
	for(i = 0; i< 5; i++){
		array[i] = i;
	}
	
	/*输出数组各元素的值*/
	for(i = 0; i< 5; i++){
		printf(RED"%d\n"NONE, array[i]);
	}
	
	/*输出数组各元素的地址*/
	for(i = 0; i< 5; i++){
		printf(GREEN"&array[%d]...%p\n"NONE, i, &array[i]);
	}

    return 0;
}
