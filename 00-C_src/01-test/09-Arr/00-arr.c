#include <stdio.h>

int main(void)
{
	int i;
	int a[5] = {1, 2, 3, 4, 5};
	int *p =a;
#if (0)
	for(i = 0; i < 5; i++)
		printf("a[%d] = %d\n",i,a[i]);
#else
	for(i = 0; i < 5; i++)
		printf("%d\n",*(p+i));
#endif
	
	return 0;
}
