#include <stdio.h>

int fun0(void)	//表示该函数没有参数
{
	return 100;
}

void fun1(int x)	//表示该函数无需返回值
{
	printf("x = %d\n",x);
}

int main(void)
{
	fun1(fun0());

	return 0;
}
