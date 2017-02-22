#include <stdio.h>

int main(void)
{
	int a = 5,b = 3;

#if 0
	if(a < b &&(a = 100))
		printf("断路运算测试！\n");
	printf("a = %d\tb = %d\n",a,b);
#else
	if(a > b &&(a = 100))
		printf("断路运算测试！\n");
	printf("a = %d\tb = %d\n",a,b);
#endif

	return 0;
}
