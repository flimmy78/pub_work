#include <stdio.h>


void fun(void)
{
	unsigned int word = 0x12345678;
	unsigned char byte = *(unsigned char *)&word;
	unsigned char byte1 = *((unsigned char *)&word+1);
	unsigned char byte2 = *((unsigned char *)&word+2);
	unsigned char byte3 = *((unsigned char *)&word+3);

	printf("%hhx\n",byte);
	printf("%hhx\n",byte1);
	printf("%hhx\n",byte2);
	printf("%hhx\n",byte3);
	if(byte == 0x78)
		printf("该机器为小端序!\n");
	else
		printf("该机器为大端序!\n");
}


int main(void)
{
	fun();
	return 0;
}
