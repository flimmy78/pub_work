#include <stdio.h>

void fun1(void)
{
	int a = 0;	//自动存储类型
	static int b = 0;	//局部static静态存储类型

	a++;
	b++;

	printf("a = %d\t",a);
	printf("b = %d\n",b);
}

int main(void)
{
	fun1();
	fun1();
	fun1();
	return 0;
}
