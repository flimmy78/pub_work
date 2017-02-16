#include <stdio.h>

int main(void)
{
	int a = 5,b = 3,c;

	c = a < b ? a : b;
	printf("c = %d\n",c);

	return 0;
}
