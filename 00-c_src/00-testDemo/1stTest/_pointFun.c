/*指针函数：返回指针的函数，例如：int *p(int) */

#include <stdio.h>

char *fun(void)
{
	return "Hello , World !";
}

int main(void)
{
	char *str;

	str = fun();
	printf("%s\n",str);

	return 0;
}
