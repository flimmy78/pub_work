#include <stdio.h>

int main(void)
{
	int i;
	int a[2][5] = {1,2,3,4,5,
					6,7,8,9,10};

#if 0
	int (*p)[5] = a;
	for(i = 0; i < 5; i++)
	{
		printf("%d\n",*(*p+i));
	}
#else
	int *p = a[0];
	for(i = 0; i < 10; i++)
	{
		printf("%d\n",*(p+i));
	}
#endif
	return 0;
}
