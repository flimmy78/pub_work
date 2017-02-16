#include <stdio.h>

#define MIN(x, y) (((x)>(y)) ? (y) : (x))

int main(void)
{
	int x=1, y=2;
	printf("the MIN one is: %d\n", MIN(x, y));
	return 0;
}
