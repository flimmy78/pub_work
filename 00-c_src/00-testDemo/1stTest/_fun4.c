#include <stdio.h>

void fun4(int *x,int *y)
{
	*x = 100;
	*y = 200;
}

int main(void)
{
	int a = 5, b = 3;

	printf("a = %d\tb = %d\n",a,b);
	fun4(&a,&b);
	printf("a = %d\tb = %d\n",a,b);

	return 0;
}
