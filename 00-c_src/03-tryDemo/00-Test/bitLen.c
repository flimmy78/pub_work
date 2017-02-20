#include <stdio.h>

int main(void)
{
	printf("char          存储大小：%u\n",sizeof(char));
	printf("unsigned char 存储大小：%u\n",sizeof(unsigned char));
	printf("short         存储大小：%u\n",sizeof(short));
	printf("unsigned short存储大小：%u\n",sizeof(unsigned short));
	printf("int           存储大小：%u\n",sizeof(int));
	printf("unsigned int  存储大小：%u\n",sizeof(unsigned int));
	printf("long          存储大小：%u\n",sizeof(long));
	printf("unsigned long 存储大小：%u\n",sizeof(unsigned long));
	printf("float         存储大小：%u\n",sizeof(float));
	printf("double        存储大小：%u\n",sizeof(double));
	printf("long int      存储大小：%u\n",sizeof(long int));
	printf("long long     存储大小：%u\n",sizeof(long long));
	printf("long double   存储大小：%u\n",sizeof(long double));

	return 0;
}
