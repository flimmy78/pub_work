#include <stdio.h>

int fun3(int a, int  b);

int main(void)
{
	int a = 5, b = 3;
	int ret;

	ret = fun3(a,b);
	printf("ret = %d\n",ret);
	printf("a = %d\tb = %d\n",a,b);

	return 0;
}

int fun3(int x,int y)
{
	int sum;

	sum = x + y;
	x = 100;
	y = 200;
	printf("x = %d\ty = %d\n",x,y);

	return sum;
}
