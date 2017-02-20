#include <stdio.h>

/*如果函数中定义了与全局变量同名的变量，则函数中不能再使用同名的全局变量*/
int x1 = 100;	//全局变量
int x2;
int x3;

void fun(int x)
{
	int x2 = 123;

	printf("in_fun :x1 = %d\n",x1);
	printf("in_fun :x2 = %d\n",x2);		//x2不再是全局变量
	printf("in_fun :x3 = %d\n",x3);
}

int x2 = 200;	//全局变量

int main(void)
{
	fun(1);

	printf("in_main :x1 =%d\n",x1);
	printf("in_main :x2 = %d\n",x2);
	printf("in_main :x3 = %d\n",x3);

	return 0;
}

int x3 = 300;	//全局变量


