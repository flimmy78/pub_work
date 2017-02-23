#include <stdio.h>

int main(void)
{
	int a;
	float b;
	double c;

	a = 123;
	b = 23.45;
	c = 123.456;
	
	printf("a=%d,b=%f,c=%f\n",a,b,c);
	printf("a=%d,b=%f\n",100,1.2);
	printf("a=%d\n",100+120);
	printf("%s\n","hello world");
	printf("%%\n");
	return 0;
}
