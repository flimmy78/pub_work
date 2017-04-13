#include <stdio.h>

int main(void)
{
	int a = 5, b = 3,c;

	c = (a = 10,c = b,a += b);
	printf("a = %d \n",a);
	printf("b = %d \n",b);
	printf("c = %d \n",c);

	return 0;
}
