#include <stdio.h>

int main(void)
{
	double i = 500000000;

	printf("After 5 0000 0000 !");
	for(; i > 0; i--);
	printf("\n");
	return 0;
}
