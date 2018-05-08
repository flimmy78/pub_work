/*******************************************************************
 *   > File Name: 01-sizeof.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月24日 星期二 13时38分05秒
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("sizeof(char): 						%d\n", sizeof(char));
	printf("sizeof(unsigned char): 				%d\n", sizeof(unsigned char));
	printf("sizeof(signed char): 				%d\n", sizeof(signed char));
	printf("sizeof(int): 						%d\n", sizeof(int));
	printf("sizeof(unsigned int): 				%d\n", sizeof(unsigned int));
	printf("sizeof(short): 						%d\n", sizeof(short));
	printf("sizeof(unsigned short): 			%d\n", sizeof(unsigned short));
	printf("sizeof(long): 						%d\n", sizeof(long));
	printf("sizeof(unsinged long): 				%d\n", sizeof(unsigned long));
	printf("sizeof(long long): 					%d\n", sizeof(long long));
	
    return 0;
}
