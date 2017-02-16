#include <stdio.h>

void fun(void)   //回调函数
{
	printf("hello world!\n");
}

void print(void(*p)(void))
{
	p();
}

int main(void)
{
	print(fun);
	return 0;
}
