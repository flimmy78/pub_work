#include <stdio.h>

/*即可以打印全局变量，也可以修改全局变量*/
int x1 = 100;	//全局变量
int x2;
int x3;

void fun(int x)
{
	//int x2;
	x1 = 789;
	x2 = 123;
	x3 = 456;
}

int x2 = 200;	//全局变量

int main(void)
{
	fun(1);
	printf("in_main : x1 = %d\n",x1);
	printf("in_main : x2 = %d\n",x2);
	printf("in_main : x3 = %d\n",x3);

	return 0;
}

int x3 = 300;	//全局变量

