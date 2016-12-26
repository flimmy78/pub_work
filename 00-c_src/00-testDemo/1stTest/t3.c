#include <stdio.h>

int main(void)
{
	int a = 0;

	while(a > 0)
	{
		printf("先判断，OK就进入循环！\n");
	}

	do{
		printf("先进入循环，再判断！\n");
	}while(a > 0);

	return 0;
}
