#include <stdio.h>

int fun2(int a,int b);

int main(void)
{
	int a = 5, b =3;
	int ret;

	ret = fun2(a,b);
	printf("ret = %d\n",ret);
	
	return 0;
}

int fun2(int a, int b)
{
	int sum;

	sum = a + b;
	return sum;
}
