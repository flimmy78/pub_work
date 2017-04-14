#define DEBUG

#include <stdio.h>

int main(void)
{
#ifdef DEBUG
	printf("1.-------\n");
#else
	printf("2.-------\n");
#endif

	return 0;
}
