#include <stdio.h>

int main(void)
{
	if((0x01 & (0xff >> 4)))
	{
		printf("true\n");
	}
	else
	{
		printf("faluse\n");
	}

	return 0;
}
