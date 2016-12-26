#include <stdio.h>

int test_fun(void)
{
	char buf[256];
	int a;

	fgets(buf, sizeof(buf), stdin);
	sscanf(buf,"%d",&a);
	printf("a = %d \n",a);

	return 0;
}

int main(void)
{
	test_fun();

	return 0;
}
