#include <stdio.h>


int x1 = 100;	 //全局非static静态存储
static int x2 = 200;	 //全局static静态存储

void fun2(void)
{
	x1 *= 2;
	x2 *= 2;
}
void fun3(void)
{
	printf("x1 = %d\n",x1);
	printf("x2 = %d\n",x2);
}


