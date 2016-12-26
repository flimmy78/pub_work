#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool bl;

	bl = 100;
	printf("bl = %d\n",bl);		//结果为真：1
	bl = -100;
	printf("bl = %d\n",bl);		//结果为真：1
	bl = 0;
	printf("bl = %d\n",bl);		//结果为假：0

	return 0;
}
