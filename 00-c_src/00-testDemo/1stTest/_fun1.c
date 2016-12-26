#include <stdio.h>

int fun1(int a, int b)
{
	int sum;

	sum = a + b;
	
	return sum;
}

int main(void)
{
	int x,y,ret;

	x=100,y=1000;
	ret = fun1(x,y);
	printf("ret = %d\n",ret);

	return 0;
}
