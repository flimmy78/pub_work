#include <stdio.h>

int main(void)
{
	int a;
	static int ret;

A:
	while((ret = scanf("%d",&a)) != 1)
	{
		printf("输入错误，重新输入！\n");
        goto A;
	}
	if(ret == 1)
		printf("a = %d\n",a);

	return 0;
}
