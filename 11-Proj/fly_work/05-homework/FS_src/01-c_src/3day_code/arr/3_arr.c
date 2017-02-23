#include <stdio.h>


int main(void)
{
	int a[10] = {[3] = 100,101,102,[8] = 80,[4]=400,500};

	printf("a[3] = %d\n",a[3]);
	printf("a[4] = %d\n",a[4]);
	printf("a[5] = %d\n",a[5]);

	return 0;
}
