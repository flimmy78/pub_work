#include <stdio.h>

int main(void)
{
	int i;

	i = 1;
A:
	if(i % 2 == 0)
		goto B;
	i++;
	printf("i = %d\n",i);
	goto A;
B:
	
	return 0;
}
