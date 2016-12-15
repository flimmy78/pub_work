#include <stdio.h>

int main(void)
{
	int a;
	float b;
	double c;

	a = 12;
	b = 12.34;
	c = 123.456;

	printf("a = %d,b = %f,c = %f\n",a,b,c);
	printf("a = %d,b = %f\n",100,1.2);
	printf("a = %d\n",100+500);
	printf("%s\n","Hello world");
	printf("%%\n");

	char ch = 'A';
	short a0 = 100;
	int a1 = 123;
	long a2 = 456;
	long long a3 = 123456;
	float b0 = +5.6;

	printf("%+5d\n",a1);
	printf("%-5d\n",a1);
	printf("%+f\n",b0);
	printf("%.2f\n",b0);
	printf("%hd,%d,%ld\n",a0,a1,a2);
	printf("%hhd\n",ch);
	printf("%lld\n",a3);

	return 0;
}
