#include <stdio.h>

#define m 60
int main(void)
{
	int min;

	scanf("%d",&min);
	printf("%d 分钟 等于%d小时%d分钟!\n",min,min/m,min%m);
	return 0;
}
