#include <stdio.h>

#define DEBUG_TEST

int DecToHex(int Dec)
{
	printf("Hex :0x%x\n",Dec);

	return 0;
}

#ifdef DEBUG_TEST
int main(void)
{

	while(1)
	{
		int decimal;
		printf("Pls input a decimal number:");
		scanf("%d",&decimal);
		DecToHex(decimal);
	}

	return 0;
}
#endif
