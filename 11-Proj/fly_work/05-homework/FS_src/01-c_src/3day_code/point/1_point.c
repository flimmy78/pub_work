#include <stdio.h>

int main(void)
{
	int a = 100;
	//int *p = &a;    //对p初始化，即定义p的同时给p赋值。

	int *p;
	p = &a;

	printf("&a = %p\n",&a);
	printf("p = %p\n",p);
	printf("a = %d\n",a);
	printf("*p= %d\n",*p);

	return 0;
}
