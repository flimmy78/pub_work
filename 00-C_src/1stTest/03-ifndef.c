#include <stdio.h>

//#define DEBUG_TEST

#ifndef DEBUG_TEST
int main(void)
{
	printf("1\n");

	return 0;
}
#else
int main(void)
{
	printf("2\n");
		
	return 0;
}
#endif
