#include <stdio.h>

void fun()
{
	unsigned int word = 0x12345678;

	unsigned char byte0 = *((unsigned char *)&word+0);
	unsigned char byte1 = *((unsigned char *)&word+1);
	unsigned char byte2 = *((unsigned char *)&word+2);
	unsigned char byte3 = *((unsigned char *)&word+3);

	printf("%hhx\n",byte0);
	printf("%hhx\n",byte1);
	printf("%hhx\n",byte2);
	printf("%hhx\n",byte3);

	if(byte0 == 0x78)
		printf("该机器是小端序！\n");
	else
		printf("该机器是大端序！\n");
}

int main(void)
{
	fun();

	return 0;
}
