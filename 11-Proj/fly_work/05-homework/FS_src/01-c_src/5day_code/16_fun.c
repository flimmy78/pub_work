#include <stdio.h>

void fun(int n)
{
	printf("n = %d\n",n);
	n--;
	if(n > 0)
		fun(n);
}

int main(void)
{
	fun(5);
	return 0;
}
