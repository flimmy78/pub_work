#include <stdio.h>

#define FUN(a,b) a+b*a

int fun(int a, int b)
{
	return a+b*a;
}

int main(void)
{
	int a = 5, b = 3;
	int c;

	c = fun(a,b);	//函数调用
	printf("c = %d\n",c);
	c = FUN(a,b);	//宏调用
	printf("c = %d\n",c);

	float f;

	f = fun(3.1,4.5); //数据类型不正确
	printf("f = %f\n",f);
	f = FUN(3.1,4.5);
	printf("f = %f\n",f);

	return 0;
}
