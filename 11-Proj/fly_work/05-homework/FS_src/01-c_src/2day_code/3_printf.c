#include <stdio.h>

int main(void)
{
	char ch = 'A';
	short a1 = 100;
	int a = 123;
	long a2 = 200;
	long long a3 = 123456;
	float b = +5.6;

	//printf("%-5d\n",a);
	printf("%05d\n",a);
	printf("%+f\n",b);
	printf("%.2f\n",b);
	printf("%d,%hd,%ld\n",a,a1,a2);
	printf("%hhd\n",ch);
	printf("%lld\n",a3);
	return 0;
}
