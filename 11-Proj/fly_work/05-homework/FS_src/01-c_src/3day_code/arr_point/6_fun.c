#include <stdio.h>

char *fun(void)   //fun为指针函数
{
	return "hello world";
}


int main(void)
{
	char *str;

	str = fun();
	printf("%s\n",str);
	return 0;
}
