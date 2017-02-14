#include <stdio.h>

int main(void)
{
	unsigned int word = 0x12345678;

	unsigned char byte0 = *((unsigned char *)&word + 0);
	unsigned char byte1 = *((unsigned char *)&word + 1);
	unsigned char byte2 = *((unsigned char *)&word + 2);
	unsigned char byte3 = *((unsigned char *)&word + 3); 

	unsigned int *pint = &word;
	unsigned char *p0 = &byte0;
	unsigned char *p1 = &byte1;
	unsigned char *p2 = &byte2;
	unsigned char *p3 = &byte3;

	printf("%p :word = 0x%x\n",pint,word);
	printf("%p :byte0 = 0x%x\n",p0,byte0);
	printf("%p :byte1 = 0x%x\n",p1,byte1);
	printf("%p :byte2 = 0x%x\n",p2,byte2);
	printf("%p :byte3 = 0x%x\n",p3,byte3);

	if(byte0 == 0x78)
		printf("小端序！\n");
	else
		printf("大端序！\n");
	
	return 0;
}
