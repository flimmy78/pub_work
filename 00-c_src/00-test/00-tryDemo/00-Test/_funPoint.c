#include <stdio.h>

/*函数的入口地址，例如：fun（函数的地址）或&fun（函数的取地址）
 *函数指针：指向函数的指针，例如：int (*p)(int);
 */
void fun(int x, int y)
{
	printf("x = %d\t y = %d\n",x,y);
}

int main(void)
{
	int a = 5 ,b = 3;

	void (*p)(int ,int);	//p为指针函数
	p = fun;
	p(a,b);

	return 0;
}
