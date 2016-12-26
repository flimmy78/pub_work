#include <stdio.h>
#define _My_DEBUG

int main(void)
{
#ifdef My_DEBUG
	printf("IN ifdef no define !\n");
#else
	printf("---->IN ifdef no define else !\n");
#endif
	printf("OUT ifdef no define !\n");

#ifdef _My_DEBUG
	printf("IN ifdef define !\n");
#else
	printf("---->IN ifdef define else !\n");
#endif


#define MY_DEBUG_
#ifndef MY_DEBUG_
	printf("IN ifndef define !\n");
#else
	printf("---->IN ifndef define else !\n");
#endif

	return 0;
}
